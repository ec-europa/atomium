<?php

/**
 * @file
 * Vertical_tabs.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_vertical_tabs() {
  return array(
    'vertical_tabs' => array(
      'render element' => 'element',
      'template' => 'vertical_tabs',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_vertical_tabs(&$variables) {
  drupal_add_library('system', 'drupal.vertical-tabs');
  $variables['attributes_array']['class'][] = 'vertical-tabs-panes';
}
