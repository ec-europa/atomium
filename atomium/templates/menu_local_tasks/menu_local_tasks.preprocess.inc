<?php

/**
 * @file
 * menu_local_tasks.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_preprocess_menu_local_tasks(&$variables) {
  if (!empty($variables['primary'])) {
    $variables['menu'][] = $variables['primary'];
  }
  if (!empty($variables['secondary'])) {
    $variables['menu'][] = $variables['secondary'];
  }
}
