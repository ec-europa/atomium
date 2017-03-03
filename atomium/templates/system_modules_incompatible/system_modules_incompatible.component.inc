<?php

/**
 * @file
 * System_modules_incompatible.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__system_modules_incompatible() {
  return array(
    'system_modules_incompatible' => array(
      'variables' => array('message' => NULL),
      'template' => 'system-modules-incompatible',
    ),
  );
}

/**
 * Implements hook_preprocess_system_modules_incompatible().
 */
function atomium_preprocess_system_modules_incompatible(&$variables) {
  $variables['attributes_array']['class'][] = 'incompatible';
}
