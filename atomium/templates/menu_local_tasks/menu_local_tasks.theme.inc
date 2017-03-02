<?php

/**
 * @file
 * menu_local_tasks.theme.inc
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
