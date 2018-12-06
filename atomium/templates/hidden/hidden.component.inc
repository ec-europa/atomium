<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_hidden() {
  return array(
    'hidden' => array(
      'render element' => 'element',
      'template' => 'hidden',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_hidden(array &$variables, $hook) {
  // Special fix for Views Bulk Operation.
  // By default, VBO creates hidden components and set the class as string.
  // The class attributes needs to be an array.
  if (isset($variables['element']['#attributes']['class']) &&
    !\is_array($variables['element']['#attributes']['class'])) {
    $variables['element']['#attributes']['class'] = array(
      $variables['element']['#attributes']['class'],
    );
  }

  _form_set_class($variables['element'], array('form-hidden'));
  element_set_attributes($variables['element'], array('id', 'name', 'value'));
  $attributes = _atomium_get_attributes($variables['element']);
  $variables['element']['#attributes']['class'] = array(
    $variables['element']['#attributes']['class'],
  );
  $attributes['type'] = 'hidden';

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
