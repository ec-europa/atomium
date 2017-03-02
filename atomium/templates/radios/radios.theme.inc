<?php

/**
 * @file
 * radios.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__radios() {
  return array(
    'radios' => array(
      'render element' => 'element',
      'template' => 'radios',
    ),
  );
}
