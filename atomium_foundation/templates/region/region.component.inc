<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_region(&$variables, $hook) {
  if (strpos($variables['elements']['#region'], 'sidebar') !== FALSE) {
    $variables['attributes_array']['class'][] = 'large-3';
    $variables['attributes_array']['class'][] = 'columns';
  }
}
