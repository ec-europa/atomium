<?php

/**
 * @file
 * form_element.inc
 */

/**
 * Implements hook_form_element().
 */
function atomium_form_element($variables) {
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

  if ($attributes['class']) {
    $output = '<div' . drupal_attributes($attributes) . '>' . "\n";
  }
  else {
    $output = "\n" . '<div>' . "\n";
  }

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= "\n" . '<small>' . $element['#description'] . "</small>\n";
  }

  $output .= "</div>\n";

  return $output;
}
