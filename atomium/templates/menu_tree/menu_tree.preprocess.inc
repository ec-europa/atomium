<?php

/**
 * @file
 * menu_tree.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_tree().
 */
function atomium_preprocess_menu_tree(&$variables) {
  $variables['attributes_array']['class'][] = 'menu';
  $variables['attributes_array']['class'][] = 'hook__menu_tree';
  if (isset($variables['theme_hook_original'])) {
    $variables['attributes_array']['class'][] = 'hook__' . $variables['theme_hook_original'];
  }
}
