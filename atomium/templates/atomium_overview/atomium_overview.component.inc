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

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_atomium_overview(&$variables, $hook) {
  $variables['definitions'] = atomium_get_component_definitions();
}
