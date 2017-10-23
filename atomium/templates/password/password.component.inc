<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_password() {
  return array(
    'password' => array(
      'render element' => 'element',
      'template' => 'password',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_password(&$variables, $hook) {
  element_set_attributes(
    $variables['element'],
    array('id', 'name', 'size', 'maxlength')
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
