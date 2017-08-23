<?php

/**
 * @file
 * Menu_local_action.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_menu_local_action(&$variables, $hook) {
  $variables[$hook]['#options']['attributes']['class'] = array(
    'btn',
    'btn-default',
  );
}
