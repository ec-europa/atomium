<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_admin_block(array $existing, $type, $theme, $path) {
  return array(
    'admin_block' => array(
      'template' => 'admin-block',
      'variables' => array(
        'block' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_admin_block() {
  return array(
    'label' => 'Admin block',
    'description' => 'Admin block description.',
    'preview' => array(
      'block' => array(
        'title' => 'Block title',
        'description' => 'Block description',
        'content' => 'Block content',
      ),
    ),
  );
}
