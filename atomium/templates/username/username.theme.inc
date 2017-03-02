<?php

/**
 * @file
 * username.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__username() {
  return array(
    'username' => array(
      'render element' => 'element',
      'template' => 'username',
      'variables' => array('account' => NULL),
    ),
  );
}
