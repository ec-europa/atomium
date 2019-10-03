<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_user_profile() {
  $user = user_load(1);

  return array(
    'label' => 'User profile',
    'description' => 'User profile description.',
    'preview' => array(
      'account' => $user,
      'view_mode' => 'full',
    ),
  );
}
