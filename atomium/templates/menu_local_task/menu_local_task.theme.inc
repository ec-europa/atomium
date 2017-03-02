<?php

/**
 * @file
 * menu_local_task.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__menu_local_task() {
  return array(
    'menu_local_task' => array(
      'render element' => 'element',
      'template' => 'menu-local-task',
      'variables' => array(
        'link' => NULL,
        'menu_link' => NULL,
        'active' => FALSE,
      ),
    ),
  );
}
