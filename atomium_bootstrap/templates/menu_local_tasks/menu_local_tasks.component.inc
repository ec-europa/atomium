<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_menu_local_tasks(&$variables, $hook) {
  if (!empty($variables['primary'])) {
    $variables['primary']['#attributes']['class'][] = array(
      'nav',
      'nav-tabs',
    );
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#attributes']['class'][] = array(
      'nav',
      'nav-pills',
    );
  }
}
