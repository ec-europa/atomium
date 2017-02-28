<?php

/**
 * @file
 * textarea.preprocess.inc
 */

/**
 * Implements hook_preprocess_textarea().
 */
function atomium_preprocess_textarea(&$variables) {
  $element = &$variables['element'];

  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _form_set_class($element, array('form-textarea'));

  if (isset($element['#title']) && !empty($element['#title'])) {
    $element['#attributes']['placeholder'] = $element['#title'];
  }

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
  }

  if (isset($element['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'textarea__' . $element['#field_name'];
  }
  if (isset($element['#entity_type'])) {
    $variables['theme_hook_suggestions'][] = 'textarea__' . $element['#entity_type'];
    if (isset($element['#field_name'])) {
      $variables['theme_hook_suggestions'][] = 'textarea__' . $element['#entity_type'] . '__' . $element['#field_name'];
    }
    if (isset($element['#bundle'])) {
      $variables['theme_hook_suggestions'][] = 'textarea__' . $element['#entity_type'] . '__' . $element['#bundle'];
    }
  }

  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $element['#attributes']);
  $variables['wrapper_attributes_array'] = $wrapper_attributes;
}
