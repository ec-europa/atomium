<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_system_compact_link(array $existing, $type, $theme, $path) {
  return array(
    'system_compact_link' => array(
      'variables' => array('link' => array()),
      'template' => 'system-compact-link',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_system_compact_link(array &$variables, $hook) {
  $variables['link'] = array(
    '#type' => 'atomium_link',
    '#theme_hook_suggestions_parts' => array(
      $variables['theme_hook_original'],
    ),
    '#title' => NULL,
    '#href' => NULL,
    '#options' => array(
      'attributes' => array(),
      'query' => drupal_get_destination(),
    ),
  );

  if (system_admin_compact_mode()) {
    $variables['link']['#title'] = t('Show descriptions');
    $variables['link']['#href'] = 'admin/compact/off';
    $variables['link']['#options']['attributes']['title'] = t('Expand layout to include descriptions.');
  }
  else {
    $variables['link']['#title'] = t('Hide descriptions');
    $variables['link']['#href'] = 'admin/compact/on';
    $variables['link']['#options']['attributes']['title'] = t('Compress layout by hiding descriptions.');
  }
}
