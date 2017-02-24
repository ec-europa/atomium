<?php

/**
 * @file
 * admin_block.inc
 */

/**
 * Implements hook_preprocess_admin_block().
 */
function atomium_preprocess_admin_block(&$variables) {
  $variables['attributes_array']['class'][] = 'admin-panel';
  $variables['attributes_array']['class'][] = $variables['block']['title'];

  if (isset($variables['block']['title'])) {
    $variables['theme_hook_suggestions'][] = 'admin_block__' . drupal_html_class($variables['block']['title']);
  }
}
