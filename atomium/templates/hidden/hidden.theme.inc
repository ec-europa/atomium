<?php

/**
 * @file
 * hidden.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__hidden() {
  return array(
    'hidden' => array(
      'render element' => 'element',
      'template' => 'hidden',
    ),
  );
}
