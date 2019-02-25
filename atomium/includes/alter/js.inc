<?php

/**
 * @file
 * js.inc
 */

/**
 * Implements hook_js_alter().
 */
function atomium_js_alter(array &$js) {
  foreach (atomium_discover_templates() as $component_data) {
    $js_file = \sprintf('%s/%s.js', $component_data['directory'], $component_data['component']);

    if (!\file_exists($js_file)) {
      continue;
    }

    $js = drupal_add_js($js_file, array(
      'group' => JS_DEFAULT,
      'every_page' => TRUE,
    ));
  }
}
