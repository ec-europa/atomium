<?php

/**
 * @file
 * element_info.inc
 */

/**
 * Implements hook_element_info_alter().
 */
function atomium_element_info_alter(&$types) {
  foreach ($types as &$type) {
    if (isset($type['#theme_wrappers'])) {
      foreach ((array) $type['#theme_wrappers'] as $key => $theme_wrapper) {
        if ($type['#type'] != $theme_wrapper) {
          $type['#theme_wrappers'][$key] = $theme_wrapper . '__' . $type['#type'];
        }
      }
    }
  }
}
