<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_foundation_preprocess_file(&$variables) {
  $variables['attributes_array']['class'][] = 'button';
  $variables['attributes_array']['class'][] = 'secondary';
}
