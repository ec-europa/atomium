<?php

/**
 * @file
 * block.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__block() {
  return array(
    'block' => array(
      'render element' => 'elements',
      'template' => 'block',
    ),
  );
}
