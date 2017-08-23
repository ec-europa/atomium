<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_checkbox() {
  return array(
    'checkbox' => array(
      'render element' => 'element',
      'template' => 'checkbox',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_checkbox(&$variables, $hook) {
  $element = &$variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes(
    $element,
    array(
      0 => 'id',
      1 => 'name',
      '#return_value' => 'value',
    )
  );

  if (!empty($element['#checked'])) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-checkbox'));
  $variables['attributes_array'] = $element['#attributes'];
}
