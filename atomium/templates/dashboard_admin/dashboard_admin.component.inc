<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_dashboard_admin(array $existing, $type, $theme, $path) {
  return array(
    'dashboard_admin' => array(
      'render element' => 'element',
      'template' => 'dashboard-admin',
    ),
  );
}
