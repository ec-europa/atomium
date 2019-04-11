<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_system_powered_by() {
  return array(
    'label' => 'System powered by',
    'description' => 'System powered by description.',
    'preview' => array(),
  );
}

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_system_powered_by(array $existing, $type, $theme, $path) {
  return array(
    'system_powered_by' => array(
      'variables' => array(),
      'template' => 'system-powered-by',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_system_powered_by(array &$variables, $hook) {
  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#markup' => t('Powered by <a href="@poweredby">Drupal</a> & <a href="@atomium_project_url">Atomium</a>', array('@poweredby' => 'https://www.drupal.org', '@atomium_project_url' => 'https://www.drupal.org/project/atomium')),
    ),
  );
}
