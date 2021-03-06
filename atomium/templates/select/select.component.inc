<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_select(array $existing, $type, $theme, $path) {
  return array(
    'select' => array(
      'render element' => 'element',
      'template' => 'select',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_select() {
  return array(
    'label' => 'Select',
    'description' => 'Select description.',
    'preview' => array(
      array(
        'title' => 'Select title',
        'options' => array(
          'option 1' => 'option 1',
          'option 2' => 'option 2',
          'option 3' => 'option 3',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_select(array &$variables, $hook) {
  element_set_attributes($variables['element'], array('id', 'name', 'size'));
  _form_set_class($variables['element'], array('form-select'));
  $attributes = _atomium_get_attributes($variables['element']);

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
