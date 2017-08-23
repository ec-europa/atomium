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
function atomium_preprocess_file(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'file';
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-file'));

  $variables['attributes_array'] = $element['#attributes'];
}
