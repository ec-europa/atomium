<?php

/**
 * @file
 * breadcrumb.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__breadcrumb() {
  return array(
    'breadcrumb' => array(
      'variables' => array('breadcrumb' => NULL),
      'template' => 'breadcrumb',
    ),
  );
}
