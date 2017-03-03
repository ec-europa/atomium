<?php

/**
 * @file
 * Button.preprocess.inc.
 */

/**
 * Implements hook_preprocess_button().
 */
function atomium_europa_preprocess_button(&$variables) {
  $variables['attributes_array']['class'][] = 'btn';
  $variables['attributes_array']['class'][] = 'btn-default';
}
