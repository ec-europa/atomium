<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_radio() {
  return array(
    'radio' => array(
      'render element' => 'element',
      'template' => 'radio',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_radio(&$variables) {
  $element = &$variables['element'];
  $element['#attributes']['type'] = 'radio';
  element_set_attributes(
    $element,
    array(
      0 => 'id',
      1 => 'name',
      '#return_value' => 'value',
    )
  );

  if (isset($element['#return_value']) && $element['#value'] !== FALSE && $element['#value'] == $element['#return_value']) {
    $element['#attributes']['checked'] = 'checked';
  }
  _form_set_class($element, array('form-radio'));
  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $element['#attributes']);
}
