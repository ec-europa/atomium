<?php

/**
 * @file
 * Menu_local_task.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_local_task().
 */
function atomium_foundation_preprocess_menu_local_task(&$variables) {
  if (is_array($variables['menu_link'])) {
    $variables['menu_link']['#options']['attributes'] = $variables['attributes'];
    $variables['menu_link']['#options']['attributes']['class'][] = 'small';
    $variables['menu_link']['#options']['attributes']['class'][] = 'button';
    if ($variables['active'] == TRUE) {
      $variables['menu_link']['#options']['attributes']['class'][] = 'primary';
    }
    else {
      $variables['menu_link']['#options']['attributes']['class'][] = 'secondary';
    }
  }
}
