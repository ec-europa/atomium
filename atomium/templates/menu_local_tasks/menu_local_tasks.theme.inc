<?php

/**
 * @file
 * menu_local_tasks.theme.inc
 */

function atomium_theme__menu_local_tasks() {
  return array(
    'menu_local_tasks' => array(
      'render element' => 'element',
      'template' => 'menu-local-tasks',
      'variables' => array(
        'primary' => array(),
        'secondary' => array(),
        'menu' => array(),
      ),
    ),
  );
}
