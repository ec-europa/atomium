<?php

/**
 * @file
 * File admin_block.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__admin_block_content() {
  return array(
    'admin_block_content' => array(
      'template' => 'admin-block-content',
      'variables' => array(
        'content' => NULL,
      ),
    ),
  );
}
