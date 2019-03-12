<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_ellipsis(array $existing, $type, $theme, $path) {
  return array(
    'pager_ellipsis' => array(
      'template' => 'pager-ellipsis',
      'variables' => array(
        'text' => '…',
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager_ellipsis() {
  return array(
    'label' => 'Pager ellipsis',
    'description' => 'Pager ellipsis description.',
  );
}
