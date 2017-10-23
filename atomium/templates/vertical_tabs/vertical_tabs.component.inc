<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_vertical_tabs() {
  return array(
    'vertical_tabs' => array(
      'render element' => 'element',
      'template' => 'vertical-tabs',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_vertical_tabs(&$variables, $hook) {
  drupal_add_library('system', 'drupal.vertical-tabs');

  $variables['atomium']['attributes']['wrapper']->append('class', 'vertical-tabs-panes');
}
