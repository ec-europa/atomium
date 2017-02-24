<?php

/**
 * @file
 * form_element_label.inc
 */

/**
 * Implements hook_form_element_label().
 *
 * Remove the class="option" from the label
 * remove the * from a required element and add it in  class instead
 * if required its added as a class to the label dont add a * to the markup we
 * can take care of business in the css
 * Removed the for="#id" for html5 if its an item, radios, checkboxes or managed
 * file cause they aren't needed there.
 */
function atomium_form_element_label($variables) {
  $element = $variables['element'];

  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if (empty($element['#title']) && empty($element['#required'])) {
    return '';
  }

  $attributes = array();
  $required = FALSE;
  if (!empty($element['#required'])) {
    $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';
    $attributes['class'] = 'required';
  }

  $title = filter_xss_admin($element['#title']);

  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  // FOR attribute
  // in html5 we need an element for the for id items & check
  // TODO: clean this up.
  if (!empty($element['#id'])) {
    // Not every element in drupal comes with an #id
    // that we can use for the for="#id"
    // AND.
    if (
      // If its html5 & is not an item, checkboxradios or manged file.
      $element['#type'] != "item" &&
      $element['#type'] != "checkboxes" &&
      $element['#type'] != "radios" &&
      $element['#type'] != "managed_file") {
      $attributes['for'] = $element['#id'];
    }
    else {
      $attributes['for'] = $element['#id'];
    }
  }

  // The leading whitespace helps visually separate fields from inline labels.
  if ($required) {
    $output = ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>";
  }
  else {
    $output = ' <label' . drupal_attributes($attributes) . '>' . $t('!title', array('!title' => $title)) . "</label>";
  }

  return $output;
}
