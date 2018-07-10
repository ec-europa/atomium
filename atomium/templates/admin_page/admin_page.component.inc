<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_admin_page() {
  return array(
    'admin_page' => array(
      'template' => 'admin-page',
      'variables' => array(
        'container' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_admin_page(array &$variables, $hook) {
  $variables['toggle_link'] = array(
    '#theme' => 'system_compact_link',
  );
  _atomium_extend_theme_property(
    $variables['toggle_link'],
    array($variables['theme_hook_original']));

  $stripe = 0;
  $container = array();

  foreach ($variables['blocks'] as $block) {
    if (0 == $block['has_children']) {
      continue;
    }
    if (empty($block['position'])) {
      // Perform automatic striping.
      $block['position'] = (++$stripe % 2) ? 'left' : 'right';
    }
    $admin_block = array(
      '#theme' => 'admin_block',
      '#block' => $block,
      '#position' => $block['position'],
    );
    _atomium_extend_theme_property(
      $admin_block,
      array($variables['theme_hook_original']));
    $container[$block['position']][] = $admin_block;
  }

  $variables['container'] = $container;
}
