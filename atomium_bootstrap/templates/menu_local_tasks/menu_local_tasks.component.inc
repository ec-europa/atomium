<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_menu_local_tasks(&$variables, $hook) {
  $variables['primary']['#attributes']['class'][] = 'nav';
  $variables['primary']['#attributes']['class'][] = 'nav-tabs';
  $variables['secondary']['#attributes']['class'][] = 'nav';
  $variables['secondary']['#attributes']['class'][] = 'nav-pills';
}
