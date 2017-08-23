<?php

/**
 * @file
 * field.inc
 */

/**
 * Implements hook_field_attach_view_alter().
 */
function atomium_field_attach_view_alter(&$output, $context) {
  foreach (element_children($output) as $key) {
    $suggestion_data = array(
      '#field_type',
      '#entity_type',
      '#view_mode',
      '#bundle',
    );

    $suggestions = array_filter(array_map(function($item) use($output, $key) {
      return isset($output[$key][$item]) ? $output[$key][$item] : NULL;
    }, $suggestion_data));

    if (isset($output[$key]['#theme']) && !empty($suggestions)) {
      $output[$key]['#theme'] = array($output[$key]['#theme'] . '__' . implode('__', $suggestions));
    }
  }
}
