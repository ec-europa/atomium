<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_checkboxes() {
  return array(
    'checkboxes' => array(
      'render element' => 'element',
      'template' => 'checkboxes',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_checkboxes(&$variables, $hook) {
  _form_set_class($variables['element'], array('form-checkboxes'));
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
