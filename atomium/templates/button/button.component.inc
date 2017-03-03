<?php

/**
 * @file
 * Button.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
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
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_atomium_definition_button() {
  return array(
    'label' => 'Button',
    'description' => 'Button template.',
    'preview' => array(
      'type' => 'submit',
      'value' => 'Save',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_button(&$variables) {
  $element = &$variables['element'];
  // This allows us to modify the type of button we want.
  $element['#attributes']['type'] = $element['#button_type'] ?: 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  // Remove the content of all "buttons" if they are not of type "button".
  // Does it make sense? erm...
  if ('button' != $element['#attributes']['type']) {
    $element['#value'] = '';
  }

  $variables['attributes_array'] = $element['#attributes'];
}
