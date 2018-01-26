<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_textarea() {
  return array(
    'textarea' => array(
      'render element' => 'element',
      'template' => 'textarea',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_textarea(&$variables, $hook) {
  element_set_attributes(
    $variables['element'],
    array('id', 'name', 'cols', 'rows', 'title', '#title' => 'placeholder')
  );
  _form_set_class($variables['element'], array('form-textarea'));

  $attributes = _atomium_get_attributes($variables['element']);

  $wrapper_attributes_array = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($variables['element']['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes_array['class'][] = 'resizable';
  }

  if (isset($variables['element']['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'textarea__' .
      $variables['element']['#field_name'];
  }
  if (isset($variables['element']['#entity_type'])) {
    $variables['theme_hook_suggestions'][] = 'textarea__' .
      $variables['element']['#entity_type'];
    if (isset($variables['element']['#field_name'])) {
      $variables['theme_hook_suggestions'][] = 'textarea__' .
        $variables['element']['#entity_type'] . '__' .
        $variables['element']['#field_name'];
    }
    if (isset($variables['element']['#bundle'])) {
      $variables['theme_hook_suggestions'][] = 'textarea__' .
        $variables['element']['#entity_type'] . '__' .
        $variables['element']['#bundle'];
    }
  }

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);

  if (isset($variables['element']['#atomium']['attributes']['wrapper'])) {
    $variables['atomium']['attributes']['wrapper']
      ->merge($variables['element']['#atomium']['attributes']['wrapper']);
  }

  $variables['atomium']['attributes']['wrapper']
    ->merge($wrapper_attributes_array);
}
