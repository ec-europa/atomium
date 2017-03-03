<?php

/**
 * @file
 * System_modules_incompatible.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_system_modules_incompatible() {
  return array(
    'system_modules_incompatible' => array(
      'variables' => array('message' => NULL),
      'template' => 'system-modules-incompatible',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_system_modules_incompatible(&$variables) {
  $variables['attributes_array']['class'][] = 'incompatible';
}
