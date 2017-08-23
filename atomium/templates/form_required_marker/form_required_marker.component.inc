<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_form_required_marker() {
  return array(
    'form_required_marker' => array(
      'template' => 'form-required-marker',
      'variables' => array(
        'title' => '*',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_form_required_marker(&$variables, $hook) {
  $t = get_t();

  $attributes = array(
    'class' => array(
      'form-required',
    ),
    'title' => $t('This field is required.'),
  );

  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $attributes);
}
