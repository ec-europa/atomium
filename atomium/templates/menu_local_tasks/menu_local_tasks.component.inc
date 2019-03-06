<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_local_tasks() {
  return array(
    'menu_local_tasks' => array(
      'template' => 'menu-local-tasks',
      'variables' => array(
        'primary' => array(),
        'secondary' => array(),
        'primary_attributes_array' => array(),
        'secondary_attributes_array' => array(),
        'type' => 'ul',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_local_tasks(array &$variables, $hook) {
  $primary = '';
  if ($variables['primary']) {
    $primary = array(
      '#theme' => 'item_list',
      '#items' => $variables['primary'],
      '#type' => $variables['type'],
      '#attributes' => $variables['atomium']['attributes']['primary']->getValuesAsArray(),
      '#wrapper_attributes' => array(),
    );

    _atomium_extend_theme_property(
      $primary,
      array('primary', $primary['#type'], $variables['theme_hook_original']));
  }

  $secondary = '';
  if ($variables['secondary']) {
    $secondary = array(
      '#theme' => 'item_list',
      '#items' => $variables['secondary'],
      '#type' => $variables['type'],
      '#attributes' => $variables['atomium']['attributes']['secondary']->getValuesAsArray(),
      '#wrapper_attributes' => array(),
    );
    _atomium_extend_theme_property(
      $secondary,
      array('secondary', $secondary['#type'], $variables['theme_hook_original']));
  }

  $variables['primary'] = $primary;
  $variables['secondary'] = $secondary;
}
