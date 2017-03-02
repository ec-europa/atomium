<?php

/**
 * @file
 * textfield.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__textfield() {
  return array(
    'textfield' => array(
      'render element' => 'element',
      'template' => 'textfield',
    ),
  );
}
