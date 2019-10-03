<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_password(array $existing, $type, $theme, $path) {
  return array(
    'password' => array(
      'render element' => 'element',
      'template' => 'password',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_password() {
  return array(
    'label' => 'Password',
    'description' => 'Password description.',
    'preview' => array(
      array(
        'title' => 'Password field',
        'description' => 'Password field description',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_password(array &$variables, $hook) {
  element_set_attributes(
    $variables['element'],
    array(
      0 => 'id',
      1 => 'name',
      2 => 'size',
      3 => 'maxlength',
      '#title' => 'placeholder',
    )
  );
  _form_set_class($variables['element'], array('form-text'));

  $attributes = _atomium_get_attributes($variables['element']);
  $attributes['type'] = 'password';

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
