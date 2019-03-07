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
function _atomium_theme(array &$existing, $type, $theme, $path) {
  $hooks = array();

  foreach (atomium_find_templates() as $component_data) {
    $file = \sprintf('%s/%s.component.inc', $component_data['directory'], $component_data['component']);
    if (!\file_exists($file)) {
      continue;
    }
    include_once $file;
    $function_name = $component_data['theme'] . '_atomium_theme_' . $component_data['component'];

    if (!\function_exists($function_name)) {
      continue;
    }

    $hooks = \array_map(
      function ($hook) use ($component_data) {
        $hook += array(
          'path' => $component_data['directory'],
          'file' => \sprintf('%s.component.inc', $component_data['component']),
        );

        return $hook;
      },
      drupal_array_merge_deep(
        (array) \call_user_func_array(
          $function_name,
          array(&$existing, $type, $component_data['theme'], $path)),
        $hooks
      )
    );
  }

  return $hooks;
}

/**
 * Implements hook_theme_registry_alter().
 */
function atomium_theme_registry_alter(array &$registry) {
  $components = array();
  $themes = array();

  // Prepare an array of files to include.
  foreach (atomium_find_templates() as $component_info) {
    // Save the themes in use for later use.
    $themes[$component_info['theme']] = $component_info['theme'];

    // Ensure the key exists and is an array.
    $components += array($component_info['component'] => array());

    // Merge existing component 'includes' files so we ensure that each files
    // of each theme is use are included.
    $components[$component_info['component']] = array_merge(
      $components[$component_info['component']],
      $component_info['includes']
    );
  }

  \array_walk($registry, function (array &$info, $hook) use ($components, $themes) {
    // Make sure there is a preprocess for each hook.
    $info += array(
      'preprocess functions' => array(),
      'includes' => array(),
    );

    $base_hook = atomium_get_base_hook($hook);
    $components += array($base_hook => array());

    $info['includes'] = \array_unique(
      \array_merge(
        $info['includes'],
        $components[$base_hook]
      )
    );

    // Ensure '[THEME]_preprocess' callbacks are first in the list.
    foreach (array_reverse($themes) as $theme) {
      $theme_preprocess = $theme . '_preprocess';

      // Remove current '[THEME]_preprocess' callback and add it later.
      $info['preprocess functions'] = \array_filter(
        $info['preprocess functions'],
        function ($preprocess) use ($theme_preprocess) {
          return $preprocess !== $theme_preprocess;
        }
      );

      // Add back '[THEME]_preprocess' at the first place instead.
      \array_unshift(
        $info['preprocess functions'],
        $theme_preprocess
      );
    }
  });
}
