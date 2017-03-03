<?php

/**
 * @file
 * Includes atomium_overview theme functions.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_atomium_overview() {
  return array(
    'atomium_overview' => array(
      'template' => 'atomium-overview',
      'variables' => array('definitions' => array()),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_atomium_overview(&$variables, $hook) {
  $variables['definitions'] = atomium_get_component_definitions();
}
