<?php

/**
 * @file
 * textarea.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__textarea() {
  return array(
    'textarea' => array(
      'render element' => 'element',
      'template' => 'textarea',
    ),
  );
}
