<?php

/**
 * @file
 * Menu_tree.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_tree().
 */
function atomium_foundation_preprocess_menu_tree(&$variables, $hook) {
  if (1 != $variables['depth']) {
    $variables[$hook]['#attributes']['class'][] = 'nested';
  }

  $variables[$hook]['#attributes']['class'][] = 'menu';

  if ('menu_tree__main_menu' == $variables['theme_hook_original']) {
    $variables[$hook]['#attributes']['class'][] = 'dropdown';
    $variables[$hook]['#attributes'][] = 'data-dropdown-menu';
  }
  else {
    $variables[$hook]['#attributes']['class'][] = 'vertical';
  }
}
