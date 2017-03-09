<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_foundation_preprocess_region(&$variables, $hook) {
  if (strpos($variables['elements']['#region'], 'sidebar') !== FALSE) {
    $variables[$hook]['#attributes']['class'][] = 'large-3';
    $variables[$hook]['#attributes']['class'][] = 'columns';
  }
}
