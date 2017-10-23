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
      'variables' => array(
        'block' => NULL,
      ),
    ),
  );
}
