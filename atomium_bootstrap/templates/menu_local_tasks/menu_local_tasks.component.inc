<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_bootstrap_preprocess_menu_local_tasks(&$variables) {
  $variables['primary_attributes_array']['class'][] = 'nav';
  $variables['primary_attributes_array']['class'][] = 'nav-tabs';
  $variables['secondary_attributes_array']['class'][] = 'nav';
  $variables['secondary_attributes_array']['class'][] = 'nav-pills';
}
