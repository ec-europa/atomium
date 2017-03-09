<?php

/**
 * @file
 * Menu_local_action.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_local_action().
 */
function atomium_foundation_preprocess_menu_local_action(&$variables, $hook) {
  unset($variables[$hook]['#theme_wrappers']);
  $variables[$hook][$hook]['#options']['attributes']['class'] = array(
    'button',
    'secondary',
  );
}
