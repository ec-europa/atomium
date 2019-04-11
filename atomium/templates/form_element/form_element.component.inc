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
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function atomium_preprocess_form_element(array &$variables, $hook) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array();
  // Date selects need the form-item for the show/hide end date.
  if (isset($element['#type'])) {
    // AND.
    if ($element['#type'] === 'date_select' || $element['#type'] === 'date_text' || $element['#type'] === 'date_popup') {
      $attributes['class'] = array('form-item');
    }
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . \str_replace($element['#type'], '_', '-');
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

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  $variables['description'] = '';
  if (!empty($element['#description'])) {
    $variables['description'] = $element['#description'];
  }

  $variables['element'] += array(
    '#field_suffix' => '',
    '#field_prefix' => '',
  );

  $variables['label'] = array(
    '#theme' => _atomium_extend_theme_hook('form_element_label', $variables['theme_hook_original']),
    'element' => $variables['element'],
  );

  $variables['atomium']['attributes']['wrapper']->merge($attributes);
}
