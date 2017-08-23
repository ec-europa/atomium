<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_ellipsis() {
  return array(
    'pager_ellipsis' => array(
      'template' => 'pager-ellipsis',
      'variables' => array(
        'text' => '…',
      ),
    ),
  );
}
