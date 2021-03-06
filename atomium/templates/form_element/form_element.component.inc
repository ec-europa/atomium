<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_form_element(array $existing, $type, $theme, $path) {
  return array(
    'form_element' => array(
      'template' => 'form-element',
      'render element' => 'element',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_form_element(array &$variables, $hook) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  $variables['label'] = array();
  if ($element['#title_display'] !== 'none' && $element['#title_display'] !== 'attribute') {
    // Build the label render array manually.
    $variables['label'] = array(
      '#theme' => 'form_element_label',
      '#element' => $element,
      '#title_display' => $element['#title_display'],
      '#title' => isset($element['#title']) ? $element['#title'] : NULL,
      '#id' => isset($element['#id']) ? $element['#id'] : NULL,
      '#required' => isset($element['#required']) ? $element['#required'] : NULL,
    );
  }

  _atomium_extend_theme_property(
    $variables['label'],
    array($variables['theme_hook_original'])
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . \str_replace('_', '-', $element['#type']);
  }

  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . \strtr(
      $element['#name'],
        array(' ' => '-', '_' => '-', '[' => '-', ']' => '')
      );
  }

  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }

  $variables['description'] = '';
  if (!empty($element['#description'])) {
    $variables['description'] = $element['#description'];
  }

  $element += array(
    '#field_suffix' => '',
    '#field_prefix' => '',
  );

  $variables['atomium']['attributes']['wrapper']->merge($attributes);
}
