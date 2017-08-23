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
function atomium_preprocess_field(&$variables) {
  $variables += array('attributes_array' => array());
  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
  $variables['content_attributes_array']['class'][] = 'field-items';

  $attributes_item = array();
  foreach ($variables['items'] as $delta => $item) {
    $classes = array('field-item ', ($delta % 2 ? 'odd' : 'even'));
    $attributes_item[$delta]['class'] = $classes;
  }

  $variables['attributes_item'] = $attributes_item;
}

/**
 * Implements hook_process_hook().
 */
function atomium_process_field(&$variables) {
  foreach ($variables['attributes_item'] as &$attribute) {
    $attribute = atomium_drupal_attributes($attribute);
  }
}
