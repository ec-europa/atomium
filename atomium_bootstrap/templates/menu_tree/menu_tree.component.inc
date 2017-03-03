<?php

/**
 * @file
 * Menu_tree.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_tree().
 */
function atomium_bootstrap_preprocess_menu_tree(&$variables) {
  $variables['attributes_array']['class'][] = 'nav';
  $variables['attributes_array']['class'][] = 'nav-stacked';
}
