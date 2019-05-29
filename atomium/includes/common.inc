<?php

/**
 * @file
 * common.inc
 */

/**
 * Includes a theme file.
 *
 * @param string $theme
 *   Name of the theme to use for base path.
 * @param string $path
 *   Path relative to $theme.
 *
 * @return bool
 *   TRUE if file has been included, FALSE otherwise.
 */
function atomium_include($theme, $path) {
  static $themes = array();

  $themes += array(
    $theme => drupal_get_path('theme', $theme),
  );

  if ($themes[$theme] && ($file = DRUPAL_ROOT . '/' . $themes[$theme] . '/' . $path) && \file_exists($file)) {
    if (\is_dir($file)) {
      foreach (\glob($file . '/*.{inc,php}', GLOB_BRACE) as $file_to_include) {
        include_once $file_to_include;
      }
    }

    if (\is_file($file)) {
      include_once $file;
    }

    return TRUE;
  }

  return FALSE;
}

/**
 * Returns a list of base themes for active or provided theme.
 *
 * @param string $theme_key
 *   The machine name of the theme to check, if not set the active theme name
 *   will be used.
 * @param bool $include_theme_key
 *   Whether to append the returned list with $theme_key.
 *
 * @return array
 *   An indexed array of base themes.
 */
function _atomium_get_base_themes($theme_key = NULL, $include_theme_key = FALSE) {
  static $themes;

  $theme_key = $theme_key ?: $GLOBALS['theme_key'];

  if (!isset($themes[$theme_key])) {
    $themes[$theme_key] = \array_unique(
      \array_filter(
        (array) atomium_get_theme_info($theme_key, 'base theme')
      )
    );
  }

  if ($include_theme_key) {
    $themes[$theme_key][] = $theme_key;
  }

  return \array_unique($themes[$theme_key]);
}

/**
 * Return information from the .info file of a theme (and possible base themes).
 *
 * @param string $theme_key
 *   The machine name of the theme.
 * @param string $key
 *   The key name of the item to return from the .info file. This value can
 *   include "][" to automatically attempt to traverse any arrays.
 * @param bool $base_themes
 *   Recursively search base themes, defaults to TRUE.
 *
 * @return string|array|false
 *   A string or array depending on the type of value and if a base theme also
 *   contains the same $key, FALSE if no $key is found.
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function atomium_get_theme_info($theme_key = NULL, $key = NULL, $base_themes = TRUE) {
  // If no $theme_key is given, use the current theme if we can determine it.
  if ($theme_key === NULL) {
    $theme_key = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : NULL;
  }

  if ($theme_key === NULL) {
    return FALSE;
  }

  $themes = list_themes();
  if (empty($themes[$theme_key])) {
    return FALSE;
  }

  $theme = $themes[$theme_key];

  if ($key === NULL) {
    return $theme->info;
  }

  $value = FALSE;

  // Recursively add base theme values.
  if ($base_themes === TRUE && isset($theme->base_themes)) {
    foreach (\array_keys($theme->base_themes) as $base_theme) {
      $value = atomium_get_theme_info($base_theme, $key);
    }
  }

  $info = $themes[$theme_key]->info;
  // Allow array traversal.
  foreach (\explode('][', $key) as $parent) {
    if (isset($info[$parent])) {
      $info = (array) $info[$parent];
    }
    else {
      $info = array();
    }
  }

  if (!empty($info)) {
    if (\is_array($value)) {
      $value = drupal_array_merge_deep($value, $info);
    }
    elseif (empty($value)) {
      $value = $info;
    }
    else {
      $value = drupal_array_merge_deep((array) $value, $info);
    }
  }

  return $value;
}

/**
 * Retrieves an element's "attributes" array.
 *
 * @param array $element
 *   The individual renderable array element. It is possible to also pass the
 *   $variables parameter in [pre]process functions and it will logically
 *   determine the correct path to that particular theme hook's attribute array.
 *   Passed by reference.
 * @param string $property
 *   Determines which attributes array to retrieve. By default, this is the
 *   normal attributes, but can be "wrapper_attributes" or
 *   "input_group_attributes".
 *
 * @return array
 *   The attributes array. Passed by reference.
 */
function &_atomium_get_attributes(array &$element, $property = 'attributes') {
  $hash_property = '#' . $property;

  // Attempt to retrieve a renderable element attributes first.
  if (
    isset($element['#type']) ||
    isset($element['#theme']) ||
    isset($element['#pre_render']) ||
    isset($element['#markup']) ||
    isset($element['#theme_wrappers']) ||
    isset($element[$hash_property])
  ) {
    $element += array(
      $hash_property => array(),
    );

    return $element[$hash_property];
  }

  // Treat $element as if it were a [pre]process function $variables parameter
  // and look for a renderable "element".
  if (isset($element['element'])) {
    $element['element'] += array(
      $hash_property => array(),
    );

    return $element['element'][$hash_property];
  }

  // If all else fails, create (if needed) a default "attributes" array. This
  // will, at the very least, either work or cause an error that can be tracked.
  $element += array(
    $property => array(),
  );

  return $element[$property];
}

/**
 * Discover components across a theme and all its subthemes.
 */
function atomium_discover_templates() {
  foreach (_atomium_get_base_themes(NULL, TRUE) as $theme) {
    $path = drupal_get_path('theme', $theme) . '/templates';

    if (!\is_dir($path)) {
      continue;
    }

    $directories = \array_diff(
      \scandir($path, SCANDIR_SORT_ASCENDING),
      array('..', '.')
    );

    foreach ($directories as $directory) {
      $component_directory = $path . DIRECTORY_SEPARATOR . $directory;

      if (!\is_dir($component_directory)) {
        continue;
      }

      yield array(
        'theme' => $theme,
        'component' => $directory,
        'directory' => $component_directory,
        'includes' => \glob($component_directory . '/*.component.inc'),
      );
    }
  }
}

/**
 * Verbatim copy of drupal_get_breadcrumb().
 *
 * The only modified stuff are the call to menu_get_active_breadcrumb() which
 * is replaced with atomium_menu_get_active_breadcrumb().
 *
 * @see drupal_get_breadcrumb()
 */
function atomium_drupal_get_breadcrumb() {
  $breadcrumb = drupal_set_breadcrumb();

  if (!isset($breadcrumb)) {
    $breadcrumb = atomium_menu_get_active_breadcrumb();
  }

  return $breadcrumb;
}

/**
 * Verbatim copy of menu_get_active_breadcrumb().
 *
 * The difference with the original function is that this function returns
 * a render array instead of an array of links rendered.
 *
 * This will allow us to modify the data properly.
 *
 * @see menu_get_active_breadcrumb()
 */
function atomium_menu_get_active_breadcrumb() {
  $breadcrumb = array();

  // No breadcrumb for the front page.
  if (drupal_is_front_page()) {
    return $breadcrumb;
  }

  $item = menu_get_item();
  if (!empty($item['access'])) {
    $active_trail = menu_get_active_trail();

    // Allow modules to alter the breadcrumb, if possible, as that is much
    // faster than rebuilding an entirely new active trail.
    drupal_alter('menu_breadcrumb', $active_trail, $item);

    // Don't show a link to the current page in the breadcrumb trail.
    $end = \end($active_trail);
    if ($item['href'] === $end['href']) {
      \array_pop($active_trail);
    }

    // Remove the tab root (parent) if the current path links to its parent.
    // Normally, the tab root link is included in the breadcrumb, as soon as we
    // are on a local task or any other child link. However, if we are on a
    // default local task (e.g., node/%/view), then we do not want the tab root
    // link (e.g., node/%) to appear, as it would be identical to the current
    // page. Since this behavior also needs to work recursively (i.e., on
    // default local tasks of default local tasks), and since the last non-task
    // link in the trail is used as page title (see menu_get_active_title()),
    // this condition cannot be cleanly integrated into menu_get_active_trail().
    // menu_get_active_trail() already skips all links that link to their parent
    // (commonly MENU_DEFAULT_LOCAL_TASK). In order to also hide the parent link
    // itself, we always remove the last link in the trail, if the current
    // router item links to its parent.
    if (($item['type'] & MENU_LINKS_TO_PARENT) === MENU_LINKS_TO_PARENT) {
      \array_pop($active_trail);
    }

    foreach ($active_trail as $parent) {
      $breadcrumb[] = array(
        '#theme' => _atomium_extend_theme_hook('link', 'breadcrumb'),
        '#text' => $parent['title'],
        '#path' => $parent['href'],
        '#options' => $parent['localized_options'],
      );
    }
  }

  return $breadcrumb;
}

/**
 * Custom utility callback that apply to each array element, a callback.
 *
 * Unlike array_walk_recursive, this function send the key name if a value is
 * an array.
 * As the value is passed by reference, you are able to modify its value within
 * the callback.
 *
 * @param array $variables
 *   The array.
 * @param callable $callback
 *   The callback function.
 */
function atomium_recursive_foreach(array &$variables, callable $callback) {
  $variables['#atomium_recursive_processed'] = TRUE;

  // By default set the recursive to FALSE.
  $variables += array(
    '#atomium_recursive' => FALSE,
  );

  foreach ($variables as $key => &$value) {
    if (\is_array($value) && !isset($value['#atomium_recursive_processed'])) {

      // If no recursive is set, take the value by default.
      $value += array(
        '#atomium_recursive' => $variables['#atomium_recursive'],
      );

      if ($value['#atomium_recursive'] === TRUE) {
        atomium_recursive_foreach($value, $callback);
      }

      // Remove the key to avoid polluting the array with unwanted values.
      unset($value['#atomium_recursive']);
    }

    \call_user_func_array($callback, array($key, &$value, &$variables));
  }

  unset($variables['#atomium_recursive_processed']);
}

/**
 * Custom helper function.
 *
 * This helper updates the render array of a block so block preprocess are
 * correctly processed.
 *
 * @param array $block_array
 *   The original block render array.
 * @param string|null $region
 *   The region where the block is placed.
 * @param int $block_index_in_region
 *   The position of the block in the region, if any.
 * @param int $total_blocks_in_region
 *   The total number of blocks in the region.
 */
function _atomium_update_block_render_array(array &$block_array, $region = NULL, $block_index_in_region = 0, $total_blocks_in_region = 0) {
  $block_array['#block']->atomium['block_index_in_region'] = $block_index_in_region;
  $block_array['#block']->atomium['total_blocks_in_regions'] = $total_blocks_in_region;

  if (isset($block_array['#theme_wrappers'])) {
    $block_array['#theme_wrappers'] = _atomium_extend_with_suggestions(
      $block_array['#theme_wrappers'],
      array(
        \is_string($region) ? $region : NULL,
        $block_array['#block']->module,
        $block_array['#block']->delta,
      )
    );
  }
}

/**
 * Get the render array of a block.
 *
 * @param string $module
 *   The module.
 * @param string $delta
 *   The module delta.
 * @param string|null $region
 *   The region where the block is placed.
 * @param int $block_index_in_region
 *   The position of the block in the region, if any.
 * @param int $total_blocks_in_region
 *   The total number of blocks in the region.
 *
 * @return array
 *   The block render array.
 */
function _atomium_block_get_render_array($module, $delta, $region = NULL, $block_index_in_region = 0, $total_blocks_in_region = 0) {
  $block = block_load($module, $delta);

  // If not block has been loaded, return empty array.
  if (!isset($block->status)) {
    return array();
  }

  $block_render_array = _block_get_renderable_array(_block_render_blocks(array($block)));

  $block_array = array();
  if (isset($block_render_array[$module . '_' . $delta])) {
    $block_array = $block_render_array[$module . '_' . $delta];
    _atomium_update_block_render_array($block_array);
  }

  return $block_array;
}

/**
 * Extends strings with an array of suggestions.
 *
 * @param array $items
 *   The strings to extend.
 * @param array $suggestions
 *   The suggestions to add.
 *
 * @example
 *   $items = array('container', 'block');
 *   $suggestions = array('foo', 'bar');
 *
 *   The result will be: array('container__foo__bar', 'block__foo__bar')
 *
 *   Quick note about the drupal_strtolower() call:
 *   We must ensure lowercase values because get_defined_functions()
 *   in drupal_group_functions_by_prefix() returns functions in lower case.
 *
 * @see http://php.net/manual/en/function.get-defined-functions.php
 *
 * @return array
 *   The extended strings.
 */
function _atomium_extend_with_suggestions(array $items = array(''), array $suggestions = array()) {
  array_walk_recursive(
    $items,
    function (&$base_hook) use ($suggestions) {
      if ($hook = _atomium_extend_theme_hook($base_hook, $suggestions)) {
        $base_hook = $hook[0];
      }
    }
  );

  return $items;
}

/**
 * Extend a theme hook with suggestions.
 *
 * @param string|null $base
 *   The base hook.
 * @param string|array $suggestions
 *   The suggestions.
 *
 * @return array|false
 *   An array containing the theme hook extended,
 *   FALSE if the base hook is null.
 */
function _atomium_extend_theme_hook($base = NULL, $suggestions = array()) {
  if (empty($base) || !\is_string($base)) {
    return FALSE;
  }

  $suggestions = (array) $suggestions;
  \array_unshift($suggestions, $base);

  return array(
    \str_replace(
      '-',
      '_',
      drupal_strtolower(
        \implode(
          '__',
          \array_map(function ($suggestion) {
            return \trim($suggestion, '_');
          },
            \array_filter(
              $suggestions
            )
          )
        )
      )
    ),
  );
}

/**
 * Flatten an array.
 *
 * If input array is:
 *
 * $input = array(
 *   'parent1' => 'valueA'
 *   'parent2' => array(
 *     'subparent2' => 'valueB',
 *   'parent3' => array(
 *     'subparent3' => array(
 *       'valueC1',
 *       'valueC2',
 *       'valueC3',
 *       'valueC4',
 *     )
 *   )
 * );
 *
 * The output array $storage will be:
 *
 * array(
 *   'parent1' => 'valueA',
 *   'parent2.subparent2' => 'valueB',
 *   'parent3.subparent3' => array(
 *       'valueC1',
 *       'valueC2',
 *       'valueC3',
 *       'valueC4',
 *   ),
 * );
 *
 * @param array $array
 *   The input array.
 * @param array $storage
 *   The output array.
 * @param string $parentKey
 *   The parent key where to start from.
 */
function _atomium_array_flatten(array $array, array &$storage, $parentKey = '') {
  foreach ($array as $key => $value) {
    $itemKey = $parentKey;

    if (!\is_numeric($key)) {
      $itemKey .= ($parentKey ? '.' : '') . $key;
    }

    if (\is_array($value)) {
      $storage[$itemKey] = $value;
      _atomium_array_flatten($value, $storage, $itemKey);
    }
    else {
      if (\is_numeric($key)) {
        $storage += array($itemKey => array());
        $storage[$itemKey][] = $value;
      }
      else {
        $storage[$itemKey] = $value;
      }
    }
  }
}

/**
 * Get settings from the current theme info file.
 *
 * @param string $setting_keys
 *   The settings to get, flattened (concatenated with ".")
 * @param bool $base_themes
 *   TRUE to get the value in the base_themes
 *   if the settings is not found in current theme,
 *   FALSE otherwise.
 * @param array $value_callbacks
 *   The list of callbacks to apply to retrieved values.
 *
 * @return array
 *   The settings as an array.
 */
function atomium_get_settings($setting_keys, $base_themes = TRUE, array $value_callbacks = array('trim')) {
  static $drupal_static_fast;

  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['atomium_get_settings'] = &drupal_static(__FUNCTION__);
  }

  $theme_key = $GLOBALS['theme_key'];
  $cid = $theme_key;
  if ($base_themes === TRUE) {
    $cid .= '+';
  }

  $settings_by_theme = &$drupal_static_fast['atomium_get_settings'];

  if (!isset($settings_by_theme[$cid])) {
    $settings_by_theme[$cid] = array();
    if ($theme_settings = atomium_get_theme_info($theme_key, 'settings', $base_themes)) {
      _atomium_array_flatten(
        $theme_settings,
        $settings_by_theme[$cid]);
    }
  }

  $settings = $settings_by_theme[$cid];

  $setting_value = array();

  if (isset($settings[$setting_keys])) {
    if (\is_string($settings[$setting_keys])) {
      $setting_value = \explode(',', $settings[$setting_keys]);
    }

    if (\is_array($settings[$setting_keys])) {
      $setting_value = $settings[$setting_keys];
    }

    foreach ($value_callbacks as $value_callback) {
      $setting_value = \array_map($value_callback, $setting_value);
    }
  }

  return \array_filter($setting_value);
}

/**
 * Get the base hook of a hook name.
 *
 * Example:
 *   If input hook is form_element__checkbox__form_random_id,
 *   then the output base hook will be: form_element.
 *
 * @param string $hook
 *   The hook.
 *
 * @return string
 *   The base hook.
 */
function atomium_get_base_hook($hook) {
  if (FALSE !== $pos = \strpos($hook, '__')) {
    return \substr($hook, 0, $pos);
  }

  return $hook;
}

/**
 * Recursive element_children() function.
 *
 * As the default element_children() from Drupal is fine for single dimension
 * arrays, this function deal with multiple dimensions arrays.
 * It applies a callback to each Drupal element found in it.
 * The variable $context['parents'] of type string[] will hold the parents
 * hierarchy of the element.
 *
 * @param array $root_element
 *   The root element.
 * @param callable $callback
 *   A custom callback to apply to each element.
 * @param string|null $root_element_key
 *   The root element key.
 * @param array $context
 *   The context.
 */
function _atomium_recursive_element_children(array &$root_element, callable $callback, $root_element_key = NULL, array &$context = array()) {
  $context += array('parents' => array());
  $context['parents'][$root_element_key] = &$root_element;

  $callback($root_element, $root_element_key, $context);

  foreach (element_children($root_element) as $sub_element_key) {
    if (!is_array($root_element[$sub_element_key])) {
      continue;
    }
    _atomium_recursive_element_children(
      $root_element[$sub_element_key],
      $callback,
      $sub_element_key,
      $context
    );
  }

  array_pop($context['parents']);
}
