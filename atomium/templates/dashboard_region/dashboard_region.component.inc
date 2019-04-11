<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_dashboard_region(array $existing, $type, $theme, $path) {
  return array(
    'dashboard_region' => array(
      'render element' => 'element',
      'template' => 'dashboard-region',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_dashboard_region(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']
    ->set('id', $variables['element']['#dashboard_region'])
    ->append('class', 'dashboard-region');
}
