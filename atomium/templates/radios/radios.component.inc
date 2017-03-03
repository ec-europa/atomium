<?php

/**
 * @file
 * Radios.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__radios() {
  return array(
    'radios' => array(
      'render element' => 'element',
      'template' => 'radios',
    ),
  );
}

/**
 * Implements hook_preprocess_radios().
 */
function atomium_preprocess_radios(&$variables) {
  $element = $variables['element'];
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
