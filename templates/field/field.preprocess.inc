<?php

/**
 * @file
 * field.preprocess.inc
 */

/**
 * Implements hook_preprocess_field().
 */
function atomium_preprocess_field(&$variables) {
  $variables += array('attributes_array' => array());
  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
  $variables['content_attributes_array']['class'][] = 'field-items';
}
