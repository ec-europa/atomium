<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_image_button(array $existing, $type, $theme, $path) {
  return array(
    'image_button' => array(
      'render element' => 'element',
      'template' => 'image-button',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_image_button() {
  return array(
    'label' => 'Image button',
    'description' => 'Image button description.',
    'preview' => array(
      array(
        'title' => 'Image button',
        'src' => drupal_get_path('theme', 'atomium') . '/assets/images/logo.png',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_image_button(array &$variables, $hook) {
  element_set_attributes(
    $variables['element'],
    array(
      0 => 'id',
      1 => 'name',
      2 => 'value',
      3 => 'title',
      '#title' => 'alt',
    )
  );
  $attributes = _atomium_get_attributes($variables['element']);

  $attributes['type'] = 'image';
  $attributes['src'] = file_create_url($variables['element']['#src']);

  $attributes['class'][] = 'form-' . $variables['element']['#button_type'];
  if (!empty($variables['element']['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-button-disabled';
  }

  if (isset($variables['element']['#atomium']['attributes']['element'])) {
    $variables['atomium']['attributes']['element']
      ->merge($variables['element']['#atomium']['attributes']['element']);
  }

  $variables['atomium']['attributes']['element']->merge($attributes);
}
