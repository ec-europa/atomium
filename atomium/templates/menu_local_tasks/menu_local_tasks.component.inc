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
      '#theme' => 'item_list',
      '#items' => $variables['primary'],
      '#attributes' => $variables['atomium']['attributes']['primary']
        ->getValuesAsArray(),
      '#wrapper_attributes' => array(),
      '#wrapper' => FALSE,
    );

    _atomium_extend_theme_property(
      $variables['primary'],
      array(
        $variables['theme_hook_original'],
        'primary',
      )
    );
  }

  if (!empty($variables['secondary'])) {
    foreach ($variables['secondary'] as &$item) {
      $item += array(
        '#theme_wrappers' => array(),
      );
    }

    $variables['secondary'] = array(
      '#theme' => 'item_list',
      '#items' => $variables['secondary'],
      '#attributes' => $variables['atomium']['attributes']['secondary']
        ->getValuesAsArray(),
      '#wrapper_attributes' => array(),
      '#wrapper' => FALSE,
    );

    _atomium_extend_theme_property(
      $variables['secondary'],
      array(
        $variables['theme_hook_original'],
        'secondary',
      )
    );
  }
}
