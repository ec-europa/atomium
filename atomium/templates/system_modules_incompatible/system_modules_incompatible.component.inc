<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
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
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_system_modules_incompatible(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'incompatible');
}
