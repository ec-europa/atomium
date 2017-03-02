<?php

/**
 * @file
 * file.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__file() {
  return array(
    'file' => array(
      'render element' => 'element',
      'template' => 'file',
    ),
  );
}
