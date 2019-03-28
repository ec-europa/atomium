<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_radio(array $existing, $type, $theme, $path) {
  return array(
    'radio' => array(
      'render element' => 'element',
      'template' => 'radio',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_radio() {
  return array(
    'label' => 'Radio',
    'description' => 'Radio.',
    'preview' => array(
      'radio' => array(
        'title' => 'Radio title',
        'description' => 'Radio description.',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_radio(array &$variables, $hook) {
  _form_set_class($variables['element'], array('form-radio'));
  element_set_attributes(
    $variables['element'],
    array(
      0 => 'id',
      1 => 'name',
      2 => 'type',
      '#return_value' => 'value',
    )
  );
  $attributes = _atomium_get_attributes($variables['element']);

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);

  if (isset($variables['element']['#return_value']) &&
    $variables['element']['#value'] !== FALSE &&
    (string) $variables['element']['#value'] === (string) $variables['element']['#return_value']) {
    $variables['atomium']['attributes']['element']->setAttribute('checked');
  }
}
