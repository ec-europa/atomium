<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_radio() {
  return array(
    'radio' => array(
      'render element' => 'element',
      'template' => 'radio',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_radio(&$variables, $hook) {
  _form_set_class($variables['element'], array('form-radio'));
  element_set_attributes(
    $variables['element'],
    array(
      0 => 'id',
      1 => 'name',
      '#return_value' => 'value',
    )
  );
  $attributes = _atomium_get_attributes($variables['element']);
  $attributes['type'] = 'radio';

  if (isset($variables['element']['#return_value']) &&
    $variables['element']['#value'] !== FALSE &&
    $variables['element']['#value'] == $variables['element']['#return_value']) {
    $attributes['checked'] = 'checked';
  }

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
