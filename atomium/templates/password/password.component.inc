<?php

/**
 * @file
 * Password.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__password() {
  return array(
    'password' => array(
      'render element' => 'element',
      'template' => 'password',
    ),
  );
}

/**
 * Implements hook_preprocess_password().
 */
function atomium_preprocess_password(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _form_set_class($element, array('form-text'));

  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $element['#attributes']);
}
