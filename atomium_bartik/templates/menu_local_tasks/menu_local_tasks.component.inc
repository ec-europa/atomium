<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_menu_local_tasks(array &$variables, $hook) {
  if (!empty($variables['primary'])) {
    $variables['primary']['#attributes']['class'][] = array(
      'nav',
      'primary',
    );
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#attributes']['class'][] = array(
      'tabs',
      'secondary',
      'clearfix',
    );
  }
}
