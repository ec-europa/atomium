<?php

/**
 * @file
 * form_required_marker.inc
 */

/**
 * Implements hook_preprocess_form_required_marker().
 */
function atomium_preprocess_form_required_marker(&$variables) {
  $t = get_t();

  $attributes = array(
    'class' => 'form-required',
    'title' => $t('This field is required.'),
  );

  $variables['attributes_array'] = $attributes;
  $variables['title'] = '*';
  if (isset($variables['element']['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'form_required_marker__' . $variables['element']['#field_name'];
  }
}
