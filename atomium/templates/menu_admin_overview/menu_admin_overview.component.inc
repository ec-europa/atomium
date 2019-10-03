<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_admin_overview(array $existing, $type, $theme, $path) {
  return array(
    'menu_admin_overview' => array(
      'template' => 'menu-admin-overview',
      'variables' => array(
        'title' => NULL,
        'description' => MARK_NEW,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_menu_admin_overview() {
  return array(
    'label' => 'Menu admin overview',
    'description' => 'Menu admin overview description.',
    'preview' => array(
      'title' => 'Admin menu',
      'description' => 'Admin menu description',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_admin_overview(array &$variables, $hook) {
  $variables['title'] = check_plain($variables['title']);
  $variables['description'] = filter_xss_admin($variables['description']);
}
