<?php

/**
 * @file
 * Hidden.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__hidden() {
  return array(
    'hidden' => array(
      'render element' => 'element',
      'template' => 'hidden',
    ),
  );
}

/**
 * Implements hook_preprocess_hidden().
 */
function atomium_preprocess_hidden(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'hidden';
  element_set_attributes($element, array('name', 'value'));

  $variables['attributes_array'] = $element['#attributes'];
}
