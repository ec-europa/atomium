<?php

/**
 * @file
 * html-tag.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__html_tag() {
  return array(
    'html_tag' => array(
      'render element' => 'element',
      'template' => 'html-tag',
    ),
  );
}
