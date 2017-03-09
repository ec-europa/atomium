<?php

/**
 * @file
 * preprocess.inc
 */

/**
 * Implements hook_preprocess().
 */
function atomium_preprocess(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'hook__' . $hook;
  $variables['attributes_array']['class'][] = 'hook__' . $variables['theme_hook_original'];
}
