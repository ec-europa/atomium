<?php

/**
 * @file
 * admin_block.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__admin_block() {
  return array(
    'admin_block' => array(
      'template' => 'admin-block',
    ),
  );
}
