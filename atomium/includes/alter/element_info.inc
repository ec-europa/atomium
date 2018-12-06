<?php

/**
 * @file
 * element_info.inc
 */

/**
 * Implements hook_element_info_alter().
 */
function atomium_element_info_alter(array &$types) {
  foreach ($types as &$type) {
    if (isset($type['#theme_wrappers'])) {
      foreach ((array) $type['#theme_wrappers'] as $key => $theme_wrapper) {
        if ($type['#type'] !== $theme_wrapper) {
          // Using current to make sure to have the first item of the array
          // Instead of the complete array.
          $type['#theme_wrappers'][$key] = \current(
            _atomium_extend_with_suggestions(
              array($theme_wrapper),
              array($type['#type'])
            )
          );
        }
      }
    }
  }
}
