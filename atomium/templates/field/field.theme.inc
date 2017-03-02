<?php

/**
 * @file
 * field.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__field() {
  return array(
    'field' => array(
      'render element' => 'element',
      'template' => 'field',
    ),
  );
}
