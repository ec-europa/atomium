<?php

/**
 * @file
 * Menu_tree.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_menu_tree(&$variables, $hook) {
  if (1 != $variables['depth']) {
    $variables['attributes_array']['class'][] = 'nested';
  }

  $variables['attributes_array']['class'][] = 'menu';

  if ('menu_tree__main_menu' == $variables['theme_hook_original']) {
    $variables['attributes_array']['class'][] = 'dropdown';
    $variables['attributes_array'][] = 'data-dropdown-menu';
  }
  else {
    $variables['attributes_array']['class'][] = 'vertical';
  }
}
