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
function atomium_preprocess_admin_page(&$variables, $hook) {
  $variables['toggle_link'] = array(
    '#theme' => array('system_compact_link__' . $variables['theme_hook_original']),
  );

  $stripe = 0;
  $container = array();

  foreach ($variables['blocks'] as $block) {
    if (empty($block['position'])) {
      // Perform automatic striping.
      $block['position'] = ++$stripe % 2 ? 'left' : 'right';
    }
    $container[$block['position']][] = array(
      '#theme' => array('admin_block__' . $variables['theme_hook_original']),
      '#block' => $block,
      '#position' => $block['position'],
    );
  }

  $variables['container'] = $container;
}
