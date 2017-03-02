<?php

/**
 * @file
 * comment_wrapper.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__comment_wrapper() {
  return array(
    'comment_wrapper' => array(
      'render element' => 'element',
      'template' => 'comment_wrapper',
    ),
  );
}
