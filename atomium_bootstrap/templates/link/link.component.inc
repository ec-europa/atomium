<?php

/**
 * @file
 * Link.preprocess.inc.
 */

/**
 * Implements hook_preprocess_link().
 */
function atomium_bootstrap_preprocess_link(&$variables, $hook) {
  if (isset($variables['attributes_array']['id'])) {
    if ('edit-cancel' == $variables['attributes_array']['id']) {
      $variables['attributes_array']['class'][] = 'btn';
      $variables['attributes_array']['class'][] = 'btn-danger';
    }
  }
}
