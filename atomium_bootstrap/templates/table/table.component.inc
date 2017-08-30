<?php

/**
 * @file
 * Table.preprocess.inc.
 */

/**
 * Implements hook_preprocess_table().
 */
function atomium_bootstrap_preprocess_table(&$variables) {
  // As this template is not (yet?) rewritten,
  // we have to use the 'attributes' key instead of 'attributes_array'.
  $variables['attributes_array']['class'][] = 'table';
  $variables['attributes_array']['class'][] = 'table-hover';
  $variables['attributes_array']['class'][] = 'table-condensed';
}
