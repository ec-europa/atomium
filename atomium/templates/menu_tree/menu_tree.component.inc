<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_tree(array $existing, $type, $theme, $path) {
  return array(
    'menu_tree' => array(
      'template' => 'menu-tree',
      'render element' => 'tree',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_tree(array &$variables, $hook) {
  $variables += array('attributes' => array());

  $variables['depth'] = isset($variables['#tree']['#depth']) ? $variables['#tree']['#depth'] : 1;

  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'menu-tree-level-' . $variables['depth']);
  $variables['atomium']['attributes']['wrapper']
    ->merge($variables['attributes']);
}
