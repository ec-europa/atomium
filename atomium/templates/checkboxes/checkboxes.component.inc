<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_checkboxes(array $existing, $type, $theme, $path) {
  return array(
    'checkboxes' => array(
      'render element' => 'element',
      'template' => 'checkboxes',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_checkboxes() {
  return array(
    'label' => 'Checkbox group',
    'description' => 'Checkbox group.',
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_checkboxes(array $form, array &$form_state) {
  $form['element1'] = array(
    '#title' => 'Checkboxes',
    '#description' => t('Checkboxes description'),
    '#type' => 'checkboxes',
    '#options' => array(
      'item1' => t('Item 1'),
      'item2' => t('Item 2'),
      'item3' => t('Item 3'),
    ),
    '#default_value' => array('item2'),
  );

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_checkboxes(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-checkboxes'));
  element_set_attributes(
    $variables['element'],
    array('id', 'title')
  );

  $attributes = _atomium_get_attributes($variables['element']);

  if (isset($variables['element']['#atomium']['attributes']['wrapper'])) {
    $variables['atomium']['attributes']['wrapper']
      ->merge($variables['element']['#atomium']['attributes']['wrapper']);
  }

  $variables['atomium']['attributes']['wrapper']->merge($attributes);
}
