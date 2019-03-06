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
function atomium_preprocess_textarea(array &$variables, $hook) {
  element_set_attributes(
    $variables['element'],
    array('id', 'name', 'cols', 'rows', 'title', '#title' => 'placeholder')
  );

  _form_set_class($variables['element'], array('form-textarea'));

  $variables['atomium']['attributes']['element']
    ->import(_atomium_get_attributes($variables['element']), FALSE);

  $wrapper_attributes_array = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($variables['element']['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes_array['class'][] = 'resizable';
  }

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  if (isset($variables['element']['#atomium']['attributes']['wrapper'])) {
    $variables['atomium']['attributes']['wrapper']
      ->merge($variables['element']['#atomium']['attributes']['wrapper']);
  }

  $variables['atomium']['attributes']['wrapper']
    ->merge($wrapper_attributes_array);
}
