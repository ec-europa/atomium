<?php

/**
 * @file
 * form.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__form() {
  return array(
    'form' => array(
      'render element' => 'element',
      'template' => 'form',
    ),
  );
}
