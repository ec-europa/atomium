<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_europa_atomium_theme_logo() {
  return array(
    'logo' => array(
      'template' => 'logo',
      'variables' => array(),
    ),
  );
}

/**
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_europa_atomium_definition_logo() {
  return array(
    'label' => 'Logo',
    'description' => 'Logo.',
    'preview' => array(),
  );
}
