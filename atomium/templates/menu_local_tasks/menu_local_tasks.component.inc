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
  $variables['atomium']['attributes']['primary']->append('class', 'hook__' . $hook . '__primary');
  $variables['atomium']['attributes']['secondary']->append('class', 'hook__' . $hook . '__secondary');

  if ($variables['primary']) {
    $variables['primary'] = array(
      '#theme' => _atomium_extend_theme_hook('item_list', $variables['theme_hook_original'] . '__primary'),
      '#items' => $variables['primary'],
      '#type' => $variables['type'],
      '#attributes' => $variables['atomium']['attributes']['primary']->toArray(),
      '#wrapper_attributes' => array(),
    );
  }

  if ($variables['secondary']) {
    $variables['secondary'] = array(
      '#theme' => _atomium_extend_theme_hook('item_list', $variables['theme_hook_original'] . '__secondary'),
      '#items' => $variables['secondary'],
      '#type' => $variables['type'],
      '#attributes' => $variables['atomium']['attributes']['secondary']->toArray(),
      '#wrapper_attributes' => array(),
    );
  }
}
