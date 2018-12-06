<?php

/**
 * @file
 * field.inc
 */

/**
 * Implements hook_field_attach_view_alter().
 */
function atomium_field_attach_view_alter(array &$output, array $context) {
  $suggestion_data = atomium_get_settings('alter.field_attach_view_alter.keys', TRUE);

  foreach (element_children($output) as $key) {
    $suggestions = \array_filter(\array_map(function ($item) use ($output, $key) {
      return isset($output[$key]['#' . $item]) ? $output[$key]['#' . $item] : NULL;
    }, $suggestion_data));

    if (isset($output[$key]['#theme']) && !empty($suggestions)) {
      $output[$key]['#theme'] = _atomium_extend_with_suggestions(
        (array) $output[$key]['#theme'],
        $suggestions
      );
    }
  }
}
