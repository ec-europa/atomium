<?php

/**
 * @file
 * checkboxes.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__checkboxes() {
  return array(
    'checkboxes' => array(
      'render element' => 'element',
      'template' => 'checkboxes',
    ),
  );
}
