<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_field() {
  return array(
    'field' => array(
      'render element' => 'element',
      'template' => 'field',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_field(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']
    ->append('class', $variables['classes_array']);

  $variables['atomium']['attributes'][0]->append('class', 'first');
  $variables['atomium']['attributes'][count($variables['items']) - 1]
    ->append('class', 'last');
}
