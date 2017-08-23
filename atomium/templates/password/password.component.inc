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
function atomium_preprocess_password(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _form_set_class($element, array('form-text'));

  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $element['#attributes']);
}
