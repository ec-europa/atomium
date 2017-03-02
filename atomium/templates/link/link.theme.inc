<?php

/**
 * @file
 * link.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__link() {
  return array(
    'link' => array(
      'render element' => 'element',
      'template' => 'link',
      'variables' => array(
        'text' => NULL,
        'path' => NULL,
        'options' => array(),
      ),
    ),
  );
}
