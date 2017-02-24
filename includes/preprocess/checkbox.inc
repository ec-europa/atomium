<?php

/**
 * @file
 * checkbox.inc
 */

/**
 * Implements hook_preprocess_select().
 */
function atomium_preprocess_checkbox(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes(
    $element,
    array(
      'id',
      'name',
      '#return_value' => 'value',
    )
  );

  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-radio'));
  $variables['attributes_array'] = $element['#attributes'];
}
