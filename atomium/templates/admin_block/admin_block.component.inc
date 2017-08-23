<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_admin_block() {
  return array(
    'admin_block' => array(
      'template' => 'admin-block',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_admin_block(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'admin-panel';
  $variables['content_attributes_array']['class'][] = 'body';
  $variables['description_attributes_array']['class'][] = 'description';
}
