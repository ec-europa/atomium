<?php

/**
 * @file
 * Fieldset.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_fieldset() {
  return array(
    'fieldset' => array(
      'render element' => 'element',
      'template' => 'fieldset',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
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
