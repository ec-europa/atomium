<?php

/**
 * @file
 * container.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__container() {
  return array(
    'container' => array(
      'render element' => 'element',
      'template' => 'container',
    ),
  );
}
