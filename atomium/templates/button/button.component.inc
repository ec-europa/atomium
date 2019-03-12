<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_button(array $existing, $type, $theme, $path) {
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
function atomium_preprocess_button(array &$variables, $hook) {
  element_set_attributes($variables['element'], array('id', 'name', 'value'));

  $attributes = _atomium_get_attributes($variables['element']);

  // This allows us to modify the type of button we want.
  $attributes += array('type' => 'submit');
  $attributes['class'][] = 'form-button-' . $attributes['type'];

  if (!empty($variables['element']['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-button-disabled';
  }

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
