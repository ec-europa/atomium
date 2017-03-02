<?php

/**
 * @file
 * password.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__password() {
  return array(
    'password' => array(
      'render element' => 'element',
      'template' => 'password',
    ),
  );
}
