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

  // Attach a context to each menu item.
  foreach (element_children($variables['#tree']) as $item) {
    $variables['#tree'][$item]['#context'] = array(
      'parents' => array(
        $hook => $variables,
      ),
    );
  }
}
