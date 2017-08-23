<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_image_button() {
  return array(
    'image_button' => array(
      'render element' => 'element',
      'template' => 'image_button',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_image_button(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'image';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['src'] = file_create_url($element['#src']);
  if (!empty($element['#title'])) {
    $element['#attributes']['alt'] = $element['#title'];
    $element['#attributes']['title'] = $element['#title'];
  }

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  $variables['attributes_array'] = $element['#attributes'];
}
