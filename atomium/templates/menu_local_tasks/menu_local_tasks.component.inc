<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_local_tasks(array $existing, $type, $theme, $path) {
  return array(
    'menu_local_tasks' => array(
      'template' => 'menu-local-tasks',
      'variables' => array(
        'primary' => array(),
        'secondary' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_local_tasks(array &$variables, $hook) {
  if (!empty($variables['primary'])) {
    foreach ($variables['primary'] as &$item) {
      $item += array(
        '#theme_wrappers' => array(),
      );
    }

    $variables['primary'] = array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        $variables['theme_hook_original'] . '__primary'
      ),
      '#items' => $variables['primary'],
      '#attributes' => $variables['atomium']['attributes']['primary']
        ->toArray(),
      '#wrapper_attributes' => array(),
      '#wrapper' => FALSE,
    );
  }

  if (!empty($variables['secondary'])) {
    foreach ($variables['secondary'] as &$item) {
      $item += array(
        '#theme_wrappers' => array(),
      );
    }

    $variables['secondary'] = array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        $variables['theme_hook_original'] . '__secondary'
      ),
      '#items' => $variables['secondary'],
      '#attributes' => $variables['atomium']['attributes']['secondary']
        ->toArray(),
      '#wrapper_attributes' => array(),
      '#wrapper' => FALSE,
    );
  }
}
