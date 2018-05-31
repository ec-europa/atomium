<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_tree() {
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
  // Guess the depth of the menu tree by checking the depth key of a menu item.
  $variables['depth'] = 1;
  $variables += array('attributes' => array());

  if (isset($variables['#tree'])) {
    $children = element_children($variables['#tree']);
    if (isset($children[0])) {
      if ($item = $variables['#tree'][$children[0]]) {
        $variables['depth'] = $item['#original_link']['depth'];
      }
    }
  }

  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'menu_tree-level-' . $variables['depth']);
  $variables['atomium']['attributes']['wrapper']
    ->merge($variables['attributes']);
}
