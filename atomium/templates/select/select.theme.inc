<?php

/**
 * @file
 * select.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__select() {
  return array(
    'select' => array(
      'render element' => 'element',
      'template' => 'select',
    ),
  );
}
