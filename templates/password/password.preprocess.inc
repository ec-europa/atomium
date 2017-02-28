<?php

/**
 * @file
 * password.preprocess.inc
 */

/**
 * Implements hook_preprocess_password().
 */
function atomium_preprocess_password(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _form_set_class($element, array('form-text'));

  $variables['attributes_array'] = $element['#attributes'];
}
