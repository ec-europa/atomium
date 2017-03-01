<?php

/**
 * @file
 * menu_local_task.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_task().
 */
function atomium_foundation_preprocess_menu_local_task(&$variables) {
  $variables['menu_link']['#options']['attributes']['class'] = array(
    'small',
    'button',
    'secondary',
  );
}
