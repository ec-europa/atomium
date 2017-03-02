<?php

/**
 * @file
 * button.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__button() {
  return array(
    'button' => array(
      'render element' => 'element',
      'template' => 'button',
    ),
  );
}
