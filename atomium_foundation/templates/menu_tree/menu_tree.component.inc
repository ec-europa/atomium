<?php

/**
 * @file
 * Menu_tree.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_tree().
 */
function atomium_foundation_preprocess_menu_tree(&$variables) {
  $variables['attributes_array']['class'][] = 'menu';
  $variables['attributes_array']['class'][] = 'nested';
  $variables['attributes_array']['class'][] = 'vertical';
}
