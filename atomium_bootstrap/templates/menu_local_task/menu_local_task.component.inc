<?php

/**
 * @file
 * Menu_local_task.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_menu_local_task(array &$variables, $hook) {
  if (\is_array($variables['menu_link'])) {
    $variables['menu_link']['#options']['attributes_array']['class'] = array(
      'btn',
    );

  }

  if ($variables['active']) {
    $variables['atomium']['attributes']['wrapper']
      ->append('class', 'active');
  }
}
