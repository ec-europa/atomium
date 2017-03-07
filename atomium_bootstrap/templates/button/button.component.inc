<?php

/**
 * @file
 * Button.preprocess.inc.
 */

/**
 * Implements hook_preprocess_button().
 */
function atomium_bootstrap_preprocess_button(&$variables) {
  $variables['attributes_array']['class'][] = 'btn';

  if (isset($variables['element']['#attributes']['id'])) {
    if ('edit-submit' == $variables['element']['#attributes']['id']) {
      $variables['attributes_array']['class'][] = 'btn-success';
    }
    if ('edit-delete' == $variables['element']['#attributes']['id']) {
      $variables['attributes_array']['class'][] = 'btn-danger';
    }
  }
}
