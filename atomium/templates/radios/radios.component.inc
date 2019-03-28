<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_radios(array $existing, $type, $theme, $path) {
  return array(
    'radios' => array(
      'render element' => 'element',
      'template' => 'radios',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_radios() {
  return array(
    'label' => 'Radio group',
    'description' => 'Radio group.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_radios(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'Radios',
    '#description' => 'Radios description',
    '#type' => 'radios',
    '#options' => array(
      'item1' => 'Item 1',
      'item2' => 'Item 2',
      'item3' => 'Item 3',
    ),
    '#default_value' => 'item2',
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_radios(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-radios'));
  element_set_attributes(
    $variables['element'],
    array('id', 'title')
  );

  $attributes = _atomium_get_attributes($variables['element']);

  if (isset($variables['element']['#atomium']['attributes']['wrapper'])) {
    $variables['atomium']['attributes']['wrapper']
      ->merge($variables['element']['#atomium']['attributes']['wrapper']);
  }

  $variables['atomium']['attributes']['wrapper']->merge($attributes);
}
