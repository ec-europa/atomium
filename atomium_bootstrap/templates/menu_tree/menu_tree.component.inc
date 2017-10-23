<?php

/**
 * @file
 * Menu_tree.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_menu_tree(&$variables, $hook) {
  $variables[$hook]['#attributes']['class'][] = 'nav';
  $variables[$hook]['#attributes']['class'][] = 'nav-stacked';
}
