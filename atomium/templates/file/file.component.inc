<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_file() {
  return array(
    'file' => array(
      'render element' => 'element',
      'template' => 'file',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_file(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-file'));
  element_set_attributes($variables['element'], array('id', 'name', 'size'));
  $attributes = _atomium_get_attributes($variables['element']);
  $attributes['type'] = 'file';

  $variables['atomium']['attributes']['file']->merge($attributes);
}
