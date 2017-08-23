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
      'variables' => array('blocks' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_admin_page(&$variables, $hook) {
  $variables['toggle_link'] = array(
    '#theme' => array('system_compact_link'),
  );

  $stripe = 0;
  $container = array();
  foreach ($variables['blocks'] as $block) {
    if (empty($block['position'])) {
      // Perform automatic striping.
      $block['position'] = ++$stripe % 2 ? 'left' : 'right';
    }
    if (!isset($container[$block['position']])) {
      $container[$block['position']] = array();
    }
    $container[$block['position']]['attributes_array']['class'][] = $block['position'];
    $container[$block['position']]['content'][] = array(
      '#theme' => array('admin_block'),
      '#block' => $block,
    );
  }

  $variables['container'] = $container;
}

/**
 * Implements hook_process_hook().
 */
function atomium_process_admin_page(&$variables, $hook) {
  foreach ($variables['container'] as &$data) {
    $data['attributes'] = atomium_drupal_attributes($data['attributes_array']);
  }
}
