<?php

/**
 * @file
 * menu_tree.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_tree().
 */
function atomium_preprocess_menu_tree(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'hook__' . $hook;
  if (isset($variables['theme_hook_original'])) {
    $variables['attributes_array']['class'][] = 'hook__' . $variables['theme_hook_original'];
  }
}
