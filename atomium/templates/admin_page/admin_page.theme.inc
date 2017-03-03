<?php

/**
 * @file
 * admin_page.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__admin_page() {
  return array(
    'admin_page' => array(
      'template' => 'admin-page',
      'variables' => array('blocks' => NULL),
    ),
  );
}
