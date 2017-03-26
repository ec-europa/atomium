<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_bartik_preprocess_menu_local_tasks(&$variables) {
  $variables['primary']['#attributes']['class'][] = array(
    'nav',
    'primary'
  );
  $variables['secondary']['#attributes']['class'][] = array(
    'tabs',
    'secondary'
  );
}
