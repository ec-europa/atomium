<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_atomium_overview_single(array $existing, $type, $theme, $path) {
  return array(
    // I agree, the naming could be improved.
    'atomium_overview_single' => array(
      'template' => 'atomium-overview-single',
      'variables' => array(
        'definition' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_atomium_overview_single(array &$variables, $hook) {
  $variables[$variables['theme_hook_original']] = array(
    '#theme' => 'component',
    '#name' => arg(1),
    '#label' => 'foo',
  );
}
