<?php

/**
 * @file
 * List of functions used to alter the theme registry in Atomium based themes.
 */

/**
 * Stub implementation for atomium_theme().
 *
 * This base-theme's custom theme hook implementations. Never define "path"
 * or "template" as these are detected and automatically added.
 *
 * @see atomium_theme_registry_alter()
 * @see atomium_theme()
 * @see hook_theme()
 */
function _atomium_theme(&$existing, $type, $theme, $path) {
  $hooks = array();

  foreach (atomium_find_templates() as $theme => $theme_data) {
    foreach ($theme_data as $component => $component_data) {

      $file = sprintf('%s/%s.component.inc', $component_data['directory'], $component);
      if (file_exists($file)) {
        include_once $file;
        $function_name = $theme . '_atomium_theme_' . $component;
        if (function_exists($function_name)) {
          $hooks = drupal_array_merge_deep(
            (array) call_user_func_array(
              $function_name,
              array(&$existing, $type, $theme, $path)),
            $hooks
          );
          foreach ($hooks as &$hook) {
            $hook += array('path' => $component_data['directory']);
          }
        }
      }
    }
  }

  return $hooks;
}

/**
 * Implements hook_theme_registry_alter().
 */
function atomium_theme_registry_alter(array &$registry) {
  // Figure out which theme this applies to.
  $trace = debug_backtrace(0, 3);

  if (!isset($trace[2]['function'], $trace[2]['args'][0])
    || '_theme_build_registry' !== $trace[2]['function']) {
    watchdog(
      'atomium',
      'hook_theme_registry_alter() was called from an unexpected place. We cannot determine which theme this registry belongs to. Atomium functionality might not work.',
      array(),
      WATCHDOG_WARNING
    );

    return;
  }

  /* @see _theme_build_registry() */
  list($theme, $base_themes) = $trace[2]['args'];

  // Process registered hooks in the theme registry.
  _atomium_process_theme_registry(
    $registry,
    array_merge(
      $base_themes,
      array($theme->name => $theme)
    )
  );

  // Apply Atomium sauce.
  _theme_post_process_registry($registry, $base_themes, $theme);
}

/**
 * Registry post process mechanism.
 *
 * @param array $cache
 *   The registry.
 * @param object[] $base_themes
 *   The base themes.
 * @param object $theme
 *   The current theme.
 */
function _theme_post_process_registry(array &$cache, array $base_themes, $theme) {
  $prefixes_data = _atomium_theme_make_prefixes($base_themes, $theme);
  $theme_hooks = array_merge(
    $prefixes_data['theme_engine'],
    $prefixes_data['base_theme'],
    $prefixes_data['theme']);
  $grouped_functions = drupal_group_functions_by_prefix();

  // Reverse sort the registry.
  krsort($cache);

  // Iterate over each registered hook.
  foreach ($cache as $hook => &$info) {
    // The pattern to match.
    $pattern = isset($info['pattern']) ? $info['pattern'] : ($hook . '__');

    // Only process hooks that have not explicitly "turned off" patterns.
    if (empty($pattern)) {
      continue;
    }

    // Iterate over each themes objects.
    // This is in order: the theme engine, the base theme(s), the current theme.
    foreach ($theme_hooks as $theme_hook) {
      _atomium_theme_find_processors($grouped_functions, $cache, $info, $theme_hook, $hook);

      // Ensure "theme path" is set.
      $info += array(
        'theme path' => drupal_dirname($theme->filename),
      );

      // Remove this member so each hook is independent and doesn't depend or
      // inherit of it's parent hook.
      // This prevent many situations where the preprocess/process calls orders
      // are not triggered at all or in the right order.
      unset($info['base hook']);
    }

    _atomium_theme_add_processors($hook, $info, $prefixes_data);
  }

  // Registry optimization and includes fiddling.
  // This cannot be included in the previous loop as the previous loop
  // might create new members on the fly.
  foreach ($cache as $hook => &$info) {
    // Make sure the includes member of each hook is completed with its
    // parent hook.
    list($original_hook,) = explode('__', $hook);
    $info += array('includes' => array());
    $cache[$original_hook] += array('includes' => array());
    $info['includes'] = array_unique(
      array_merge(
        (array) $info['includes'],
        (array) $cache[$original_hook]['includes']
      )
    );

    // Optimize the registry.
    $info = array_filter($info);
  }

  // Sort the registry.
  ksort($cache);

  array_walk($cache, function (array &$info) {
    // Make sure there is a preprocess for each hook.
    $info += array('preprocess functions' => array());

    $info['preprocess functions'] = array_filter(
      $info['preprocess functions'],
      function ($preprocess) {
        return 'atomium_preprocess' !== $preprocess;
      }
    );

    // The simple preprocess was not used here because theme hooks defined with
    // a function doesn't trigger all the preprocess callbacks.
    // It's added at the first place so we make sure it's creating the variables
    // for hooks defined by templates and functions properly.
    array_unshift($info['preprocess functions'], 'atomium_preprocess');
  });
}

/**
 * Find the processors callbacks.
 *
 * @param array $grouped_functions
 *   An array of grouped functions.
 * @param array $cache
 *   The registry.
 * @param array $info
 *   The current hook data.
 * @param string $theme
 *   The current theme name.
 * @param string $hook
 *   The current hook.
 */
function _atomium_theme_find_processors(array $grouped_functions, array &$cache, array &$info, $theme, $hook) {
  // The pattern to match.
  $pattern = isset($info['pattern']) ? $info['pattern'] : ($hook . '__');

  foreach (_atomium_theme_processors_phases() as $phase) {
    // Find functions matching the specific theme and phase prefix.
    $prefix = $theme . '_' . $phase;

    // Grep only the functions which are within the prefix group.
    list($first_prefix,) = explode('_', $prefix, 2);
    if (isset($grouped_functions[$first_prefix]) && ($matches = preg_grep(
        '/^' . $prefix . '_' . $pattern . '/',
        $grouped_functions[$first_prefix]
      ))) {
      foreach ($matches as $match) {
        // Determine the current theme implementation.
        $base_hook = drupal_substr($match, drupal_strlen($prefix) + 1);

        if (!isset($cache[$base_hook])) {
          $cache[$base_hook] = $info;
          $cache[$base_hook]['type'] = 'theme';
        }
      }
    }
  }
}

/**
 * Add the processors to the hook.
 *
 * @param string $hook
 *   The current hook.
 * @param array $info
 *   The current hook data.
 * @param array $prefixes_data
 *   The prefixes.
 */
function _atomium_theme_add_processors($hook, array &$info = array(), array $prefixes_data = array()) {
  $hooks_stack = drupal_get_hook_parents($hook);

  foreach (_atomium_theme_processors_phases() as $phase_key => $phase) {
    $callbacks = array();

    foreach ($prefixes_data as $prefixes) {
      foreach ($prefixes as $prefix) {
        $callbacks[] = $prefix . '_' . $phase;
        // This is the code that ensure preprocess/process inheritance.
        // TODO here detect how to set 'theme path'.
        array_map(function ($hook) use (&$callbacks, $phase, $prefix) {
          $callbacks[] = $prefix . '_' . $phase . '_' . $hook;
        }, array_reverse($hooks_stack));
      }
    }

    // This is for dealing with modules implementing hook_theme_registry_alter.
    // By doing this, I make sure that no process callbacks that has been added
    // through this hook are lost.
    $info[$phase_key] = array_merge(
      $callbacks,
      array_diff($info[$phase_key], $callbacks)
    );

    // Ensure uniqueness of functions.
    $info[$phase_key] = array_unique($info[$phase_key]);

    // Make sure that the files to include are included prior filtering
    // the preprocess callbacks.
    $info += array('includes' => array());
    foreach ((array) $info['includes'] as $theme_file) {
      include_once $theme_file;
    }

    // Filter out functions that does not exist.
    $info[$phase_key] = array_filter($info[$phase_key], '\function_exists');

    // Sadly we remove preprocess and process for hooks that provides
    // a theme function. (like the date module with date_display_single).
    // We could have this in Atomium but some modules badly implementing
    // attributes handling would fail.
    if (isset($info['function'])) {
      $info[$phase_key] = array_filter($info[$phase_key], function ($function) use ($phase, $hook) {
        return FALSE !== strpos($function, $phase . '_' . $hook);
      });
    }
  }
}

/**
 * Get processors name and machine name.
 *
 * Processor functions work in two distinct phases with the process
 * functions always being executed after the preprocess functions.
 *
 * @return array
 *   The processors names and machine names.
 */
function _atomium_theme_processors_phases() {
  return array(
    'preprocess functions' => 'preprocess',
    'process functions'    => 'process',
  );
}

/**
 * Compile a list of prefixes.
 *
 * The order of this is very important.
 *
 * @param object[] $base_themes
 *   The array of base themes.
 * @param object $theme
 *   The current theme.
 *
 * @see https://api.drupal.org/api/drupal/includes!theme.inc/function/theme/7.x
 *
 * @return array
 *   The prefixes.
 */
function _atomium_theme_make_prefixes(array $base_themes, $theme) {
  return array(
    'template' => array(
      'template' => 'template',
    ),
    'module' => module_list(),
    'theme_engine' => array(
      $theme->engine => $theme->engine,
    ),
    'base_theme' => array_map(
      function ($theme) {
        return $theme->name;
      },
      $base_themes
    ),
    'theme' => array(
      $theme->name => $theme->name,
    ),
  );
}

/**
 * Group all user functions by word before first underscore.
 *
 * @return array
 *   Functions grouped by the first prefix.
 */
function drupal_group_functions_by_prefix() {
  $functions = get_defined_functions();
  $grouped_functions = array();

  // Splitting user defined functions into groups by the first prefix.
  foreach ($functions['user'] as $function) {
    list($first_prefix,) = explode('_', $function, 2);
    $grouped_functions[$first_prefix][] = $function;
  }

  return $grouped_functions;
}

/**
 * Get parents hook.
 *
 * @param string $hook
 *   The hook.
 *
 * @return array
 *   The parent hooks stack.
 */
function drupal_get_hook_parents($hook) {
  $stack = array($hook);

  while ($pos = strrpos(current($stack), '__')) {
    $stack[] = drupal_substr(current($stack), 0, $pos);
    next($stack);
  }

  return $stack;
}

/**
 * Processes registered hooks in the theme registry against list of themes.
 *
 * Discovers and fills missing elements in the theme registry. This is similar
 * to _theme_process_registry(), however severely modified for Atomium based
 * themes.
 *
 * All additions or modifications must live in `./templates`, relative to the
 * base theme or sub-theme's base folder. These files can be organized in any
 * order using sub-folders as it searches recursively.
 *
 * Adds or modifies the following theme hook keys:
 *  - `includes`: When a variables file `*.vars.php` is found.
 *  - `includes`: When a function file `*.func.php` is found.
 *  - `function`: When a specific theme hook function override is found.
 *  - `template`: When a template file `*.tpl.php` is found in. Note, if both
 *    a function and a template are defined, a template implementation will
 *    always be used and the `function` will be unset.
 *  - `path`: When a template file `*.tpl.php` is found.
 *  - `preprocess functions`: When a specific theme hook suggestion function
 *    `hook_preprocess_HOOK__SUGGESTION` is found.
 *  - `process functions` When a specific theme hook suggestion function
 *    `hook_process_HOOK__SUGGESTION` is found.
 *
 * @param array $registry
 *   The theme registry array, passed by reference.
 * @param object[] $themes
 *   The list of Drupal theme to process.
 *
 * @see atomium_theme_registry_alter()
 * @see _theme_process_registry()
 * @see _theme_build_registry()
 */
function _atomium_process_theme_registry(array &$registry, array $themes) {
  // Processor functions work in two distinct phases with the process
  // functions always being executed after the preprocess functions.
  $variable_process_phases = array(
    'preprocess functions' => 'preprocess',
    'process functions'    => 'process',
  );

  // Iterate over each theme passed.
  // Iterate over the [pre]process phases.
  foreach ($variable_process_phases as $phase_key => $phase) {
    foreach ($themes as $theme) {
      // Get the theme's base path.
      $path = drupal_dirname($theme->filename);
      $regexp = '/\.component\.inc$/';
      // Find theme function overrides.
      foreach (drupal_system_listing($regexp, $path . '/templates', 'name', 0) as $name => $file) {
        // Strip off the extension.
        if (($pos = strpos($name, '.')) !== FALSE) {
          $name = drupal_substr($name, 0, $pos);
        }

        // Transform "-" in file names to "_" to match theme hook naming scheme.
        $hook = strtr($name, '-', '_');

        // File to be included by core's theme function when a theme hook is
        // invoked.
        if (isset($registry[$hook])) {
          $registry[$hook] += array(
            $phase_key => array(),
            'includes' => array(),
          );

          // Include the file now so functions can be discovered below.
          include_once DRUPAL_ROOT . '/' . $file->uri;

          if (!in_array($file->uri, $registry[$hook]['includes'])) {
            $registry[$hook]['includes'][] = $file->uri;
          }
        }
      }

      // Process core's normal functionality.
      _theme_process_registry($registry, $theme->name, $GLOBALS['theme_key'] === $theme->name ? 'theme' : 'base_theme', $theme->name, $path);

      // Find necessary templates in the theme.
      $registry = drupal_array_merge_deep($registry, drupal_find_theme_templates($registry, '.tpl.php', $path));

      // Iterate over each registered hook.
      foreach ($registry as $hook => $info) {
        // Remove function callbacks if a template was found.
        if (isset($info['function']) && isset($info['template'])) {
          unset($registry[$hook]['function']);
        }

        // Correct template theme paths.
        if (!isset($info['theme path'])) {
          $registry[$hook]['theme path'] = $path;
        }

        // Correct the type that is implementing this override.
        $registry[$hook]['type'] = $GLOBALS['theme_path'] === $registry[$hook]['theme path'] ? 'theme' : 'base_theme';

        $registry[$hook] += array(
          $phase_key => array(),
        );

        // Sort the phase functions.
        // @see https://www.drupal.org/node/2098551
        _atomium_registry_sort_phase_functions($registry[$hook][$phase_key], $hook, $phase, $themes);

        // Setup a default "context" variable. This allows #context to be passed
        // to every template and theme function.
        // @see https://drupal.org/node/2035055
        if (isset($info['variables']) && !isset($info['variables']['context'])) {
          $registry[$hook]['variables']['context'] = array();
        }

        // Setup a default "atomium" variable.
        if (isset($info['variables']) && !isset($info['variables']['atomium'])) {
          $registry[$hook]['variables']['atomium'] = array();
        }
      }
    }
  }
}

/**
 * Ensures the phase functions are invoked in the correct order.
 *
 * @param array $functions
 *   The phase functions to iterate over.
 * @param string $hook
 *   The current hook being processed.
 * @param string $phase
 *   The current phase being processed.
 * @param array $themes
 *   An indexed array of current themes.
 *
 * @see https://www.drupal.org/node/2098551
 */
function _atomium_registry_sort_phase_functions(array &$functions, $hook, $phase, array $themes) {
  // Immediately return if there is nothing to sort.
  if (count($functions) < 2) {
    return;
  }

  $theme_functions = array();

  // Iterate over all the themes.
  foreach ($themes as $theme) {
    // Create an associative array of theme functions to ensure sort order.
    $theme_functions[$theme->name] = array();

    // Only add the function to the array of theme functions if it currently
    // exists in the $functions array.
    $function = $theme->name . '_' . $phase . '_' . $hook;
    $key = array_search($function, $functions);
    if ($key !== FALSE) {
      // Save the theme function to be added later, but sorted.
      $theme_functions[$theme->name][] = $function;

      // Remove it from the current $functions array.
      unset($functions[$key]);
    }
  }

  // Iterate over all the captured theme functions and place them back into
  // the phase functions array.
  foreach ($theme_functions as $array) {
    $functions = array_merge($functions, $array);
  }
}
