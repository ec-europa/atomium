<?php

/**
 * @file
 * Checkboxes.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
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
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_checkboxes(&$variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'][] = 'form-checkboxes';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }
  $variables['attributes_array'] = $attributes;
}
