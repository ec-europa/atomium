<?php

/**
 * @file
 * Menu_local_action.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_local_action().
 */
function atomium_foundation_preprocess_menu_local_action(&$variables, $hook) {
  $variables[$hook]['#options']['attributes']['class'][] = 'button';
  $variables[$hook]['#options']['attributes']['class'][] = 'secondary';
}
