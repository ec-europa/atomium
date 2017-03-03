<?php

/**
 * @file
 * Admin_block.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_admin_block() {
  return array(
    'admin_block' => array(
      'template' => 'admin-block',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_admin_block(&$variables, $hook) {
  // If you want classes with double underscore.
  // Set the variable 'allow_css_double_underscores' to TRUE.
  $variables['attributes_array']['class'][] = 'hook__' . $hook . '__' . $variables['block']['title'];

  if (isset($variables['block']['title'])) {
    $variables['theme_hook_suggestions'][] = 'admin_block__' . drupal_html_class($variables['block']['title']);
  }

  $variables['content_attributes_array']['class'][] = 'body';
  $variables['description_attributes_array']['class'][] = 'description';
}
