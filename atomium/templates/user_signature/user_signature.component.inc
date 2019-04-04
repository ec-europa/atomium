<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_user_signature(array $existing, $type, $theme, $path) {
  return array(
    'user_signature' => array(
      'template' => 'user-signature',
      'variables' => array(
        'signature' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_user_signature() {
  return array(
    'label' => 'User signature',
    'description' => 'User signature description.',
    'preview' => array(
      'signature' => 'Sincerely yours, Atomium.',
    ),
  );
}
