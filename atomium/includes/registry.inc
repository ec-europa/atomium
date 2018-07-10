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

  foreach (atomium_find_templates() as $atomium_based_theme => $theme_data) {
    foreach ($theme_data as $component => $component_data) {
      $file = sprintf('%s/%s.component.inc', $component_data['directory'], $component);

      if (!file_exists($file)) {
        continue;
      }

      include_once $file;
      $function_name = $atomium_based_theme . '_atomium_theme_' . $component;

      if (!function_exists($function_name)) {
        continue;
      }

      $hooks = array_map(
        function ($hook) use ($component_data, $component) {
          $hook += array(
            'path' => $component_data['directory'],
            'file' => sprintf('%s.component.inc', $component),
          );

          return $hook;
        },
        drupal_array_merge_deep(
          (array) call_user_func_array(
            $function_name,
            array(&$existing, $type, $atomium_based_theme, $path)),
          $hooks
        )
      );
    }
  }

  return $hooks;
}

/**
 * Implements hook_theme_registry_alter().
 */
function atomium_theme_registry_alter(array &$registry) {
  $components = array();

  // Prepare an array of files to include.
  foreach (atomium_find_templates() as $data) {
    foreach ($data as $component_name => $component_info) {
      foreach (glob($component_info['directory'] . '/*.component.inc') as $filename) {
        $components[$component_name][] = $filename;
      }
    }
  }

  array_walk($registry, function (array &$info, $hook) use ($components) {
    // Make sure there is a preprocess for each hook.
    $info += array(
      'preprocess functions' => array(),
      'includes' => array(),
    );

    $base_hook = atomium_get_base_hook($hook);
    $components += array($base_hook => array());

    $info['includes'] = array_unique(
      array_merge(
        $info['includes'],
        $components[$base_hook]
      )
    );

    // Remove 'atomium preprocess' callback.
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
