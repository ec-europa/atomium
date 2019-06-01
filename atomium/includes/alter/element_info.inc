<?php

/**
 * @file
 * element_info.inc
 */

/**
 * Implements hook_element_info_alter().
 */
function atomium_element_info_alter(array &$types) {
  foreach (atomium_discover_elements() as $atomium_element_data) {
    if (empty($atomium_element_data['includes'])) {
      continue;
    }

    foreach ($atomium_element_data['includes'] as $file) {
      include_once $file;
    }

    $function_name = sprintf(
      '%s_atomium_element_info_%s',
      $atomium_element_data['theme'],
      $atomium_element_data['element']
    );

    if (!\function_exists($function_name)) {
      continue;
    }

    foreach ($function_name($types) as $element_name => $new_atomium_element_data) {
      $types[$element_name] = $new_atomium_element_data;
    }
  }

  $overrides = atomium_get_settings(
    'alter.element.overrides'
  );

  foreach ($overrides as $type => $overridenBy) {
    if (isset($types[$type], $types[$overridenBy])) {
      $types[$type] = $types[$overridenBy];
    }
  }

  foreach ($types as $type => &$type_info) {
    $type_info += array('#pre_render' => array());

    // Using a non numeric key to avoid duplicates.
    $type_info['#pre_render']['atomium_pre_render_element'] = 'atomium_pre_render_element';
  }
}
