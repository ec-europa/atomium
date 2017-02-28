<?php

/**
 * @file
 * admin_block.preprocess.inc
 */

/**
 * Implements hook_preprocess_admin_block().
 */
function atomium_preprocess_admin_block(&$variables, $hook) {
  // If you want classes with double underscore.
  // Set the variable 'allow_css_double_underscores' to TRUE.
  $variables['attributes_array']['class'][] = 'hook__' . $hook . '__' . $variables['block']['title'];

  if (isset($variables['block']['title'])) {
    $variables['theme_hook_suggestions'][] = 'admin_block__' . drupal_html_class($variables['block']['title']);
  }
}
