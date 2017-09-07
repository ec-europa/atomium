<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_button() {
  return array(
    'button' => array(
      'render element' => 'element',
      'template' => 'button',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_button() {
  return array(
    'label' => 'Button',
    'description' => 'Button template.',
    'preview' => array(
      array(
        'type' => 'submit',
        'value' => 'Save',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_button(&$variables) {
  $element = &$variables['element'];
  $element += array('#button_type' => 'submit');

  // This allows us to modify the type of button we want.
  $element['#attributes']['type'] = $element['#button_type'];
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-button-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  $variables['attributes_array'] = $element['#attributes'];
}
