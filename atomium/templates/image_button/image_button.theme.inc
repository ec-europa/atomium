<?php

/**
 * @file
 * image_button.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__image_button() {
  return array(
    'image_button' => array(
      'render element' => 'element',
      'template' => 'image_button',
    ),
  );
}
