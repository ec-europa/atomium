<?php

/**
 * @file
 * Main component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_test_preprocess_more_link(array &$variables, $hook) {
  $variables['callbacks'][] = __FUNCTION__;
}
