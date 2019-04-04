<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_dashboard_disabled_blocks(array $existing, $type, $theme, $path) {
  return array(
    'dashboard_disabled_blocks' => array(
      'render element' => 'element',
      'template' => 'dashboard-disabled-blocks',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_dashboard_disabled_blocks(array &$variables, $hook) {
  $variables['disabled_blocks'] = array();

  foreach ($variables['blocks'] as $block) {
    $variables['disabled_blocks'][] = array(
      '#theme' => 'dashboard_disabled_block',
      '#block' => $block,
    );
  }
}
