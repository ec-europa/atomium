<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_actions(array $existing, $type, $theme, $path) {
  return array(
    'actions' => array(
      'template' => 'actions',
      'render element' => 'element',
    ),
  );
}
