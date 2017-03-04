<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_form_element() {
  return array(
    'form_element' => array(
      'template' => 'form-element',
      'render element' => 'element',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_form_element(&$variables, $hook) {
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
    if ($element['#type'] == 'date_select' or $element['#type'] == 'date_text' or $element['#type'] == 'date_popup') {
      $attributes['class'] = array('form-item');
    }
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr(
      $element['#name'],
        array(' ' => '-', '_' => '-', '[' => '-', ']' => '')
      );
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }

  if ((isset($element['#title']) && $element['#title'] != 'Language') && (isset($element['#required']) && $element['#required'])) {
    $attributes['class'][] = 'form-required';
  }
  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }

  $variables['description'] = '';
  if (!empty($element['#description'])) {

    $variables['description'] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#attributes' => array(
        'class' => array(),
      ),
      'text' => array(
        '#type' => 'markup',
        '#markup' => $element['#description'],
      ),
      '#context' => array(
        'parents' => array(
          $hook => $variables,
        ),
      ),
    );
  }

  $variables['element'] += array(
    '#field_suffix' => '',
    '#field_prefix' => '',
  );

  $variables['label'] = array(
    '#theme' => 'form_element_label',
    '#element' => $variables['element'],
    '#context' => array(
      'parents' => array(
        $hook => $variables,
      ),
    ),
  );
  $variables['attributes_array'] = drupal_array_merge_deep(
    $variables['attributes_array'],
    $attributes
  );
}
