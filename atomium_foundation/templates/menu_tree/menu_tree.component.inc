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
  $variables[$hook]['#attributes']['class'][] = 'vertical';
}
