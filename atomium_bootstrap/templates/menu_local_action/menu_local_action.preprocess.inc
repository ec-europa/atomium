<?php

/**
 * @file
 * menu_local_action.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_action().
 */
function atomium_bootstrap_preprocess_menu_local_action(&$variables) {
  $variables['menu_link']['#options']['attributes']['class'] = array(
    'btn',
    'btn-default',
  );
}
