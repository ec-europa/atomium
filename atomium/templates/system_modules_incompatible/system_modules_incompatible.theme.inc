<?php

/**
 * @file
 * system_modules_incompatible.theme.inc
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
