<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_radios() {
  return array(
    'radios' => array(
      'render element' => 'element',
      'template' => 'radios',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_radios(&$variables) {
  $element = &$variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-radios';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $attributes);
}
