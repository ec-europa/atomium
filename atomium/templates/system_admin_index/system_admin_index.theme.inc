<?php

/**
 * @file
 * File system_admin_index.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__system_admin_index() {
  return array(
    'admin_page' => array(
      'template' => 'admin-page',
      'variables' => array('blocks' => NULL),
    ),
  );
}
