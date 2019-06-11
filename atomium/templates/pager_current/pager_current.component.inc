<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_current(array $existing, $type, $theme, $path) {
  return array(
    'pager_current' => array(
      'template' => 'pager-current',
      'variables' => array(
        'text' => NULL,
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager_current() {
  return array(
    'label' => 'Pager current',
    'description' => 'Pager current description',
    'preview' => array(
      'text' => 'Page 3',
    ),
  );
}
