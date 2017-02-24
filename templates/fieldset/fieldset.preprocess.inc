<?php

/**
 * @file
 * fieldset.preprocess.inc
 */

/**
 * Implements hook_preprocess_fieldset().
 */
function atomium_preprocess_fieldset(&$variables) {
  $element = &$variables['element'];
  element_set_attributes($element, array('id'));

  $element += array(
    '#attributes' => array(),
    '#description' => NULL,
    '#title' => NULL,
  );

  $variables += array(
    'attributes_array' => array(),
  );

  $variables['attributes_array'] = array_merge($element['#attributes'], (array) $variables['attributes_array']);
}
