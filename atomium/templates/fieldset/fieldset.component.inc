<?php

/**
 * @file
 * Fieldset.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__fieldset() {
  return array(
    'fieldset' => array(
      'render element' => 'element',
      'template' => 'fieldset',
    ),
  );
}

/**
 * Implements hook_preprocess_fieldset().
 */
function atomium_preprocess_fieldset(&$variables) {
  $variables += array(
    'attributes_array' => array(),
    'description' => '',
  );
  $variables['title'] = '';
  if (isset($variables['element']['#title'])) {
    $variables['title'] = $variables['element']['#title'];
  }
  if (!empty($variables['element']['#description'])) {
    $variables['description'] = $variables['element']['#description'];
  }
  $variables['attributes_array']['id'] = $variables['element']['#id'];
  $variables['attributes_array']['class'] = array_merge(
    $variables['element']['#attributes']['class'],
    $variables['attributes_array']['class']
  );
}
