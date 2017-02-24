<?php

/**
 * @file
 * field.inc
 */

/**
 * Implements hook_process_field().
 */
function atomium_process_field(&$variables, $hook) {
  foreach ($variables['items'] as $delta => $item) {
    $variables['item_attributes_array'][$delta] = array('class' => array());
    $variables['item_attributes_array'][$delta]['class'][] = 'field-item';
    $variables['item_attributes_array'][$delta]['class'][] = $delta % 2 ? 'even' : 'odd';
    $variables['item_attributes'][$delta] = empty($variables['item_attributes_array'][$delta]) ? '' : drupal_attributes($variables['item_attributes_array'][$delta]);
  }
}
