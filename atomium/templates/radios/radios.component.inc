<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_radios() {
  return array(
    'radios' => array(
      'render element' => 'element',
      'template' => 'radios',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_radios(&$variables, $hook) {
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
