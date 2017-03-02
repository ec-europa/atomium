<?php

/**
 * @file
 * checkbox.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__checkbox() {
  return array(
    'checkbox' => array(
      'render element' => 'element',
      'template' => 'checkbox',
    ),
  );
}
