<?php

/**
 * @file
 * List of functions used to alter the theme registry in Atomium based themes.
 */

/**
 * Implements hook_theme_registry_alter().
 */
function atomium_theme_registry_alter(array &$registry) {
  $components = array();
  $themes = array();

  // Prepare the list of 'includes' files. Those files are ending with
  // .component.inc and they are in directories in [theme]/templates.
  // First it 'includes' files from the base themes if any, then those from
  // the current theme.
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

  // We modify each registry's item and make sure that each of them has all the
  // needed includes files.
  \array_walk(
    $registry,
    function (array &$info, $hook) use ($components, $themes) {
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
    }
  );
}
