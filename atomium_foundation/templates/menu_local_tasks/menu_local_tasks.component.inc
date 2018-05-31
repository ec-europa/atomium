<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_menu_local_tasks(array &$variables, $hook) {
  if (!empty($variables['primary'])) {
    if (isset($variables['primary']['#type'])) {
      $variables['primary']['#type'] = '';

    }
    $variables['primary']['#wrapper_attributes_array']['class'][] = array(
      'menu',
      'expanded',
      'button-group',
    );
  }
  if (!empty($variables['secondary'])) {
    if (isset($variables['secondary']['#type'])) {
      $variables['secondary']['#type'] = '';
    }
    $variables['secondary']['#wrapper_attributes_array']['class'][] = array(
      'menu',
      'expanded',
      'button-group',
    );
  }
}
