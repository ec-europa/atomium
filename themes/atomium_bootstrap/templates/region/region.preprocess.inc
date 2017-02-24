<?php

/**
 * @file
 * region.preprocess.inc
 */

/**
 * Implements hook_preprocess_region().
 */
function atomium_bootstrap_preprocess_region(&$variables) {
  if (strpos($variables['region'], 'sidebar') !== FALSE) {
    $variables['classes_array'][] = 'well';
  }
}
