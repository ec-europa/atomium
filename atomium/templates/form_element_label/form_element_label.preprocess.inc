<?php

/**
 * @file
 * form_element_label.preprocess.inc
 */

/**
 * Implements hook_preprocess_form_element_label().
 */
function atomium_preprocess_form_element_label(&$variables) {
  $element = &$variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
// Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
// Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  $variables['title'] = $t($title);

  // TODO: See how we can improve this.
  $variables['required'] = '';
  if ($variables['element']['#required']) {
    $variables['required'] = array(
      '#theme' => 'form_required_marker',
      '#title' => '*',
    );
  }
}

