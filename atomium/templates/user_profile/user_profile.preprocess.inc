<?php

/**
 * @file
 * user.preprocess.inc
 */

/**
 * Implements hook_preprocess_user_profile().
 */
function atomium_preprocess_user_profile(&$variables) {
  $variables['classes_array'][] = 'profile';
  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
}
