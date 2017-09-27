<?php

/**
 * @file
 * field.inc
 */

/**
 * Implements hook_field_attach_view_alter().
 */
function atomium_field_attach_view_alter(&$output, $context) {
  $theme_key = $GLOBALS['theme_key'];

  // Get the settings from the theme info file.
  $settings = atomium_get_theme_info($theme_key, 'settings', TRUE);
  $suggestion_data = array();
  if (isset($settings['field_attach_view_alter']) && isset($settings['field_attach_view_alter']['keys'])) {
    $field_attach_view_alter = $settings['field_attach_view_alter'];
    if (isset($field_attach_view_alter['keys']) && is_string($field_attach_view_alter['keys'])) {
      $suggestion_data = explode(',', $field_attach_view_alter['keys']);
    }
    array_walk($suggestion_data, 'trim');
  }

  foreach (element_children($output) as $key) {
    $suggestions = array_filter(array_map(function ($item) use ($output, $key) {
      return isset($output[$key]['#' . $item]) ? $output[$key]['#' . $item] : NULL;
    }, $suggestion_data));

    if (isset($output[$key]['#theme']) && !empty($suggestions)) {
      $output[$key]['#theme'] = array($output[$key]['#theme'] . '__' . implode('__', $suggestions));
    }
  }
}
