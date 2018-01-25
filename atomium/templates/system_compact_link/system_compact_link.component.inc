<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_system_compact_link() {
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
function atomium_preprocess_system_compact_link(&$variables, $hook) {
  $variables['link'] = array(
    '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
    '#text' => NULL,
    '#path' => NULL,
    '#options' => array(
      'attributes' => array(),
      'query' => drupal_get_destination(),
    ),
  );

  if (system_admin_compact_mode()) {
    $variables['link']['#text'] = t('Show descriptions');
    $variables['link']['#path'] = 'admin/compact/off';
    $variables['link']['#options']['attributes']['title'] = t('Expand layout to include descriptions.');
  }
  else {
    $variables['link']['#text'] = t('Hide descriptions');
    $variables['link']['#path'] = 'admin/compact/on';
    $variables['link']['#options']['attributes']['title'] = t('Compress layout by hiding descriptions.');
  }
}
