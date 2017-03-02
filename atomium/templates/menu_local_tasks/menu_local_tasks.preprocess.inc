<?php

/**
 * @file
 * menu_local_tasks.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_preprocess_menu_local_tasks(&$variables, $hook) {
  $variables['primary_attributes_array'] = $variables['attributes_array'];
  $variables['secondary_attributes_array'] = $variables['attributes_array'];

  $variables['primary_attributes_array']['class'][] = 'hook__' . $hook . '__primary';
  $variables['secondary_attributes_array']['class'][] = 'hook__' . $hook . '__primary';
}
