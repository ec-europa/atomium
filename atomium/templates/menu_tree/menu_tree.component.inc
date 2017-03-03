<?php

/**
 * @file
 * Menu_tree.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__menu_tree() {
  return array(
    'menu_tree' => array(
      'template' => 'menu-tree',
    ),
  );
}

/**
 * Implements hook_preprocess_menu_tree().
 */
function atomium_preprocess_menu_tree(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'hook__' . $hook;
  if (isset($variables['theme_hook_original'])) {
    $variables['attributes_array']['class'][] = 'hook__' . $variables['theme_hook_original'];
  }
}
