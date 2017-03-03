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
    $variables['menu_link']['#options']['attributes']['class'] = array(
      'small',
      'button',
      'secondary',
    );
  }
  if ($variables['active']) {
    $variables['attributes_array']['class'][] = 'active';
  }
}
