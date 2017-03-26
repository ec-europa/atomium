<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_bartik_preprocess_region(&$variables, $hook) {
  $variables['classes_array'][] = 'region';
}
