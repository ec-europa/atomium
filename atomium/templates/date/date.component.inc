<?php

/**
 * @file
 * Date.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__date() {
  return array(
    'date' => array(
      'render element' => 'element',
      'template' => 'date',
    ),
  );
}

/**
 * Implements hook_preprocess_date().
 */
function atomium_preprocess_date(&$variables) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'container-inline';
  $variables['attributes_array'] = $attributes;
  $variables['date'] = $variables['element'];

}
