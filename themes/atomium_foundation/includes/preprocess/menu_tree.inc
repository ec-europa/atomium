<?php

/**
 * @file
 * menu_tree.inc
 */

/**
 * Implements hook_preprocess_menu_tree().
 */
function atomium_foundation_preprocess_menu_tree(&$variables) {
  $variables['attributes_array']['class'][] = 'vertical';
}
