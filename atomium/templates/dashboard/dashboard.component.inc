<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_dashboard(array $existing, $type, $theme, $path) {
  return array(
    'dashboard' => array(
      'render element' => 'element',
      'template' => 'dashboard',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_dashboard(array &$variables, $hook) {
  drupal_add_css(
    drupal_get_path('module', 'dashboard') . '/dashboard.css'
  );
}
