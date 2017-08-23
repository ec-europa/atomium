<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_select() {
  return array(
    'select' => array(
      'render element' => 'element',
      'template' => 'select',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_select(&$variables, $hook) {
  $element = &$variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select'));

  if (isset($element['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'select__' . $element['#field_name'];
  }
  if (isset($element['#entity_type'])) {
    $variables['theme_hook_suggestions'][] = 'select__' . $element['#entity_type'];
    if (isset($element['#field_name'])) {
      $variables['theme_hook_suggestions'][] = 'select__' . $element['#entity_type'] . '__' . $element['#field_name'];
    }
    if (isset($element['#bundle'])) {
      $variables['theme_hook_suggestions'][] = 'select__' . $element['#entity_type'] . '__' . $element['#bundle'];
    }
  }
  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $variables['element']['#attributes']);
  $variables['options'] = form_select_options($variables['element']);
}
