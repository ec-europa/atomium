<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_progress_bar(array $existing, $type, $theme, $path) {
  return array(
    'progress_bar' => array(
      'template' => 'progress-bar',
      'variables' => array('percent' => NULL, 'message' => NULL),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_progress_bar() {
  return array(
    'label' => 'Progress bar',
    'description' => 'Progress bar description.',
    'preview' => array(
      'percent' => \mt_rand(0, 100),
    ),
  );
}
