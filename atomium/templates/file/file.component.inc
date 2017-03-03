<?php

/**
 * @file
 * File.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__file() {
  return array(
    'file' => array(
      'render element' => 'element',
      'template' => 'file',
    ),
  );
}

/**
 * Implements hook_preprocess_file().
 */
function atomium_preprocess_file(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'file';
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-file'));

  $variables['attributes_array'] = $element['#attributes'];
}
