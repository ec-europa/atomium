<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_menu_tree() {
  return array(
    'menu_tree' => array(
      'template' => 'menu-tree',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_menu_tree(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'hook__' . $hook;
  if (isset($variables['theme_hook_original'])) {
    $variables['attributes_array']['class'][] = 'hook__' . $variables['theme_hook_original'];
  }

  $item = NULL;

  // Attach a context to each menu item.
  foreach (element_children($variables['#tree']) as $item) {
    // Should we keep this ?
    $variables['#tree'][$item]['#theme'] .= '__' . $variables['theme_hook_original'];
  }

  // Guess the depth of the menu tree by checking the depth key of a menu item.
  $variables['depth'] = 1;
  if ($item) {
    $variables['depth'] = $variables['#tree'][$item]['#original_link']['depth'];
  }
  $variables['attributes_array']['class'][] = 'menu_tree-level-' . $variables['depth'];

  $variables[$hook] = array(
    $hook => array(
      '#markup' => $variables['tree'],
    ),
    '#theme_wrappers' => array('html_tag'),
    '#tag' => 'ul',
    '#attributes' => $variables['attributes_array'],
  );
}
