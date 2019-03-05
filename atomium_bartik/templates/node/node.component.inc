<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_node(array &$variables, $hook) {
  if ($variables['view_mode'] === 'full' && node_is_page($variables['node'])) {
    $variables['classes_array'][] = 'node-full';
  }
  $variables['content']['links']['#attributes']['class'][] = 'inline';
}
