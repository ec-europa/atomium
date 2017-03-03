<?php

/**
 * @file
 * Includes atomium_overview theme functions.
 */

/**
 * Implements atomium_theme__hook().
 */
function atomium_theme__atomium_overview() {
  return array(
    'atomium_overview' => array(
      'template' => 'atomium-overview',
      'variables' => array('definitions' => array()),
    ),
  );
}
