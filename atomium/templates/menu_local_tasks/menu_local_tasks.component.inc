<?php

/**
 * @file
 * Menu_local_tasks.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__menu_local_tasks() {
  return array(
    'menu_local_tasks' => array(
      'render element' => 'element',
      'template' => 'menu-local-tasks',
      'variables' => array(
        'primary' => array(),
        'secondary' => array(),
        'primary_attributes_array' => array(),
        'secondary_attributes_array' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_preprocess_menu_local_tasks(&$variables, $hook) {
  $variables['primary_attributes_array'] = $variables['attributes_array'];
  $variables['secondary_attributes_array'] = $variables['attributes_array'];

  $variables['primary_attributes_array']['class'][] = 'hook__' . $hook . '__primary';
  $variables['secondary_attributes_array']['class'][] = 'hook__' . $hook . '__primary';
}
