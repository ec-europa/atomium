<?php

/**
 * @file
 * Vertical_tabs.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__vertical_tabs() {
  return array(
    'vertical_tabs' => array(
      'render element' => 'element',
      'template' => 'vertical_tabs',
    ),
  );
}

/**
 * Implements hook_preprocess_vertical_tabs().
 */
function atomium_preprocess_vertical_tabs(&$variables) {
  drupal_add_library('system', 'drupal.vertical-tabs');
  $variables['attributes_array']['class'][] = 'vertical-tabs-panes';
}
