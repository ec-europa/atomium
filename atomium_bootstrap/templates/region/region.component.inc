<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_region(array &$variables, $hook) {
  if (FALSE !== \strpos($variables['elements']['#region'], 'sidebar')) {
    $variables['attributes_array']['class'][] = 'col-md-3';
  }
}
