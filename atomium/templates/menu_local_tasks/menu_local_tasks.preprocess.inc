<?php

/**
 * @file
 * menu_local_tasks.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_preprocess_menu_local_tasks(&$variables) {
  if (!empty($variables['primary'])) {
    // TODO: Should we keep this ?
    // These classes are only useful for Bartik.
    $variables['attributes_array']['class'] = array('tabs', 'primary');
    $variables['menu'] = $variables['primary'];
  }
  if (!empty($variables['secondary'])) {
    $variables['attributes_array']['class'] = array('tabs', 'secondary');
    $variables['menu'] = $variables['secondary'];
  }
}
