<?php

/**
 * @file
 * menu.inc
 */

/**
 * Implements hook_menu_local_tasks_alter().
 */
function atomium_bootstrap_menu_local_tasks_alter(&$data, &$router_item, $root_path) {
  if (!empty($data['actions']['output'])) {
    foreach ($data['actions']['output'] as $item) {
      $data['tabs'][0]['output'][] = $item;
    }
    $data['actions']['output'] = array();
  }

}
