<?php

/**
 * @file
 * comment.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__comment() {
  return array(
    'comment' => array(
      'render element' => 'element',
      'template' => 'comment',
    ),
  );
}
