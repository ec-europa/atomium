<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_node_admin_overview(array $existing, $type, $theme, $path) {
  return array(
    'node_admin_overview' => array(
      'template' => 'node-admin-overview',
      'variables' => array(
        'name' => NULL,
        'type' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_node_admin_overview(array &$variables, $hook) {
  $variables['name'] = check_plain($variables['name']);

  $variables['machine_name'] = t(
    '(Machine name: @type)',
    array('@type' => $variables['type']->type)
  );

  $variables['description'] = filter_xss_admin($variables['type']->description);
}
