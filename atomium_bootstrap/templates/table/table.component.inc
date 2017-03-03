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
  $variables['attributes']['class'][] = 'table';
  $variables['attributes']['class'][] = 'table-hover';
  $variables['attributes']['class'][] = 'table-condensed';
}
