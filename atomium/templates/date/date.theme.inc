<?php

/**
 * @file
 * date.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__date() {
  return array(
    'date' => array(
      'render element' => 'element',
      'template' => 'date',
    ),
  );
}
