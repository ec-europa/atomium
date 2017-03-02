<?php

/**
 * @file
 * menu_local_tasks.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_foundation_preprocess_menu_local_tasks(&$variables) {
  $variables['primary_attributes_array']['class'][] = 'menu';
  $variables['primary_attributes_array']['class'][] = 'expanded';
  $variables['primary_attributes_array']['class'][] = 'menu-centered';
  $variables['secondary_attributes_array']['class'][] = 'menu';
  $variables['secondary_attributes_array']['class'][] = 'expanded';
  $variables['secondary_attributes_array']['class'][] = 'menu-centered';
}
