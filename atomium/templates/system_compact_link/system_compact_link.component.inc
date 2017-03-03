<?php

/**
 * @file
 * System_compact_link.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__system_compact_link() {
  return array(
    'system_compact_link' => array(
      'variables' => array('link' => array()),
      'template' => 'system-compact-link',
    ),
  );
}

/**
 * Implements hook_preprocess_system_compact_link().
 */
function atomium_preprocess_system_compact_link(&$variables) {
  $variables['link'] = array(
    '#theme' => 'link',
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
