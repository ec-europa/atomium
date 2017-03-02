<?php

/**
 * @file
 * menu_local_tasks.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_bootstrap_preprocess_menu_local_tasks(&$variables) {
  $variables['attributes_array']['class'][] = 'btn-group';
  $variables['attributes_array']['class'][] = 'btn-group-justified';

  $variables['menu'] = array();
  if (!empty($variables['primary'])) {
    $variables['menu'] = $variables['primary'];
  }
  if (!empty($variables['secondary'])) {
    $variables['menu'] = $variables['secondary'];
  }
}
