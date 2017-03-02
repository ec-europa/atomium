<?php

/**
 * @file
 * menu_link.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__menu_link() {
  return array(
    'menu_link' => array(
      'render element' => 'element',
      'template' => 'menu-link',
    ),
  );
}
