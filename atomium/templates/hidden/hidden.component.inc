<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_hidden() {
  return array(
    'hidden' => array(
      'render element' => 'element',
      'template' => 'hidden',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_hidden(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'hidden';
  element_set_attributes($element, array('name', 'value'));

  $variables['attributes_array'] = $element['#attributes'];
}
