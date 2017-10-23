<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_atomium_overview() {
  return array(
    'atomium_overview' => array(
      'template' => 'atomium-overview',
      'variables' => array(
        'definitions' => atomium_get_component_definitions(),
      ),
    ),
  );
}
