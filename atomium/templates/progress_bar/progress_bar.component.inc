<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_progress_bar() {
  return array(
    'progress_bar' => array(
      'template' => 'progress-bar',
      'variables' => array('percent' => NULL, 'message' => NULL),
    ),
  );
}
