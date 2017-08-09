<?php

/**
 * @file
 * js.inc
 */

/**
 * Implements hook_js_alter().
 */
function atomium_js_alter(&$js) {
  foreach (atomium_find_templates() as $theme_data) {
    foreach ($theme_data as $component => $component_data) {
      $js_file = sprintf('%s/%s.js', $component_data['directory'], $component);
      if (file_exists($js_file)) {
        $js = drupal_add_js($js_file, array(
          'group' => JS_DEFAULT,
          'every_page' => TRUE,
        ));
      }
    }
  }
}
