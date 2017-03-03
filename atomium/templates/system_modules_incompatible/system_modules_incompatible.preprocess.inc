<?php

/**
 * @file
 * system_modules_incompatible.preprocess.inc
 */

/**
 * Implements hook_preprocess_system_modules_incompatible().
 */
function atomium_preprocess_system_modules_incompatible(&$variables) {
  $variables['attributes_array']['class'][] = 'incompatible';
}
