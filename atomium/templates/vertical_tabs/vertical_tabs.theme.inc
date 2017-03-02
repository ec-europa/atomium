<?php

/**
 * @file
 * vertical_tabs.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__vertical_tabs() {
  return array(
    'vertical_tabs' => array(
      'render element' => 'element',
      'template' => 'vertical_tabs',
    ),
  );
}
