<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_system_admin_index() {
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
function atomium_preprocess_system_admin_index(&$variables, $hook) {
  $container = array('left' => array(), 'right' => array());
  $flip = array('left' => 'right', 'right' => 'left');
  $position = 'left';

  // Iterate over all modules.
  foreach ($variables['menu_items'] as $module => $block) {
    list($description, $items) = $block;

    // Output links.
    if (count($items)) {
      $block = array();
      $block['title'] = $module;
      $block['content'] = array(
        '#theme' => array('admin_block_content'),
        '#content' => $items,
      );
      $block['description'] = t('@description', array('@description' => $description));
      $block['show'] = TRUE;

      if (!isset($block['position'])) {
        // Perform automatic striping.
        $block['position'] = $position;
        $position = $flip[$position];
      }
      $container[$block['position']]['attributes_array']['class'][] = $block['position'];
      $container[$block['position']]['content'][] = array(
        '#theme' => array('admin_block'),
        '#block' => $block,
      );
    }
  }

  foreach ($container as &$data) {
    $data['attributes'] = atomium_drupal_attributes($data['attributes_array']);
  }

  $variables['container'] = $container;
  $variables['attributes_array']['class'][] = 'admin';

  $variables['toggle_link'] = array(
    '#theme' => array('system_compact_link'),
  );
}
