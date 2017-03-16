<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_foundation_preprocess_menu_local_tasks(&$variables) {
  $variables['primary']['#type'] = '';
  $variables['secondary']['#type'] = '';
  $variables['primary']['#wrapper_attributes_array']['class'][] = array(
    'menu',
    'expanded',
    'button-group',
  );
  $variables['secondary']['#wrapper_attributes_array']['class'][] = array(
    'menu',
    'expanded',
    'button-group',
  );
}
