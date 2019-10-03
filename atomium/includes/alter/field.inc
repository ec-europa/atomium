<?php

/**
 * @file
 * field.inc
 */

/**
 * Implements hook_field_attach_view_alter().
 */
function atomium_field_attach_view_alter(array &$output, array $context) {
  $context += array(
    'suggestion data' => atomium_get_settings(
      'alter.field_attach_view_alter.keys',
      TRUE
    ),
  );

  $callback = static function (&$root_element, $root_element_key, $context) {
    if (!isset($root_element['#theme'])) {
      return;
    }

    $suggestions = \array_filter(
      \array_map(
        static function ($item) use ($root_element) {
          return isset($root_element['#' . $item]) ?
            $root_element['#' . $item] :
            NULL;
        },
        $context['suggestion data']
      )
    );

    if (empty($suggestions)) {
      return;
    }

    $root_element['#theme'] = _atomium_extend_with_suggestions(
      (array) $root_element['#theme'],
      $suggestions
    );
  };

  _atomium_recursive_element_children(
    $output,
    $callback,
    NULL,
    $context
  );
}
