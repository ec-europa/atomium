<?php

/**
 * @file
 * Checkbox.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__checkbox() {
  return array(
    'checkbox' => array(
      'render element' => 'element',
      'template' => 'checkbox',
    ),
  );
}

/**
 * Implements hook_preprocess_select().
 */
function atomium_preprocess_checkbox(&$variables) {
  $element = $variables['element'];
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
  _form_set_class($element, array('form-radio'));
  $variables['attributes_array'] = $element['#attributes'];
}
