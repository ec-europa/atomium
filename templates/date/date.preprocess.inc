<?php

/**
 * @file
 * date.preprocess.inc
 */

/**
 * Implements hook_preprocess_select().
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
}
