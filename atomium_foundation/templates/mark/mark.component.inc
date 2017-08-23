<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_mark(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'label';
  $variables['attributes_array']['class'][] = 'info';
}
