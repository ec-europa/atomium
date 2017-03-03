<?php

/**
 * @file
 * Form_element.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__form_element() {
  return array(
    'form_element' => array(
      'template' => 'form-element',
      'render element' => 'element',
    ),
  );
}

/**
 * Implements hook_preprocess_form_element().
 */
function atomium_preprocess_form_element(&$variables) {
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
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#attributes' => array(
        'class' => array(),
      ),
      'text' => array(
        '#type' => 'markup',
        '#markup' => $element['#description'],
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
  );
}
