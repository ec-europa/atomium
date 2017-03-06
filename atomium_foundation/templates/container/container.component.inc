<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_foundation_preprocess_container(&$variables) {
  if (isset($variables['element']['#type']) && $type = $variables['element']['#type']) {
    if ('actions' == $type) {
      $variables['attributes_array']['class'][] = 'button-group';
      $variables['attributes_array']['class'][] = 'expanded';
    }
  }
}
