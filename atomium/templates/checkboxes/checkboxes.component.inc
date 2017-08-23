<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_checkboxes() {
  return array(
    'checkboxes' => array(
      'render element' => 'element',
      'template' => 'checkboxes',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_checkboxes(&$variables) {
  $element = $variables['element'];
  $attributes = $variables['attributes_array'];

  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';

  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  $variables['attributes_array'] = $attributes;
}
