<?php

/**
 * @file
 * element_info.inc
 */

/**
 * Implements hook_element_info_alter().
 */
function atomium_element_info_alter(array &$types) {
  foreach ($types as $type => $type_info) {
    if (!isset($type_info['#theme_wrappers'])) {
      continue;
    }

    foreach ((array) $type_info['#theme_wrappers'] as $key => $theme_wrapper) {
      if ($type_info['#type'] === $theme_wrapper) {
        continue;
      }

      // Using current to make sure to have the first item of the array
      // Instead of the complete array.
      $types[$type]['#theme_wrappers'][$key] = \current(
        _atomium_extend_with_suggestions(
          array($theme_wrapper),
          array($type_info['#type'])
        )
      );
    }
  }
}
