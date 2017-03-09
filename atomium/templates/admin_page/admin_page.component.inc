<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
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
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_admin_page(&$variables, $hook) {
  $variables['toggle_link'] = array(
    '#theme' => 'system_compact_link__' . $variables['theme_hook_original'],
    '#context' => array(
      'parents' => array(
        $hook => $variables,
      ),
    ),
  );

  $stripe = 0;
  $container = array();
  foreach ($variables['blocks'] as $block) {
    if (empty($block['position'])) {
      // Perform automatic striping.
      $block['position'] = ++$stripe % 2 ? 'left' : 'right';
    }
    if (!isset($container[$block['position']])) {
      $container[$block['position']] = '';
    }
    $container[$block['position']]['attributes_array']['class'][] = $block['position'];
    $container[$block['position']]['content'][] = array(
      '#theme' => 'admin_block__' . $variables['theme_hook_original'],
      '#block' => $block,
      '#context' => array(
        'parents' => array(
          $hook => $variables,
        ),
      ),
    );
  }

  foreach ($container as $id => &$data) {
    $data['attributes'] = atomium_drupal_attributes($data['attributes_array']);
  }

  $variables['container'] = $container;
  $variables['attributes_array']['class'][] = 'admin';
}
