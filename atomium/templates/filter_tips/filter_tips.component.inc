<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_filter_tips() {
  return array(
    'filter_tips' => array(
      'template' => 'filter-tips',
      'variables' => array('tips' => NULL, 'long' => FALSE),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_filter_tips(&$variables) {
  // TODO: Rewrite the template into something cleaner.
}
