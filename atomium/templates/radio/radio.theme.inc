<?php

/**
 * @file
 * radio.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__radio() {
  return array(
    'radio' => array(
      'render element' => 'element',
      'template' => 'radio',
    ),
  );
}
