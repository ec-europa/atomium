<?php

/**
 * @file
 * hidden.preprocess.inc
 */

/**
 * Implements hook_preprocess_hidden().
 */
function atomium_preprocess_hidden(&$variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'hidden';
  element_set_attributes($element, array('name', 'value'));

  $variables['attributes_array'] = $element['#attributes'];
}
