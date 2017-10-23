<?php

/**
 * @file
 * Menu_local_task.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_menu_local_task(&$variables, $hook) {
  if (is_array($variables[$hook][$hook])) {
    $variables[$hook][$hook]['#options']['attributes']['class'][] = array(
      'small',
      'button',
    );
    if ($variables['active'] == TRUE) {
      $variables[$hook][$hook]['#options']['attributes']['class'][] = 'primary';
    }
    else {
      $variables[$hook][$hook]['#options']['attributes']['class'][] = 'secondary';
    }
  }
}
