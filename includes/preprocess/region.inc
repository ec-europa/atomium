<?php

/**
 * @file
 * region.inc
 */

/**
 * Implements hook_preprocess_region().
 */
function atomium_preprocess_region(&$variables) {
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('region')));
  $variables['attributes_array']['class'] = $variables['classes_array'];
}
