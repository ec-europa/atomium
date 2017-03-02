<?php

/**
 * @file
 * status_messages.preprocess.inc
 */

/**
 * Implements hook_preprocess_status_messages().
 */
function atomium_bootstrap_preprocess_status_messages(&$variables) {
  $status_mapping = array(
    'error' => 'alert-danger',
    'status' => 'alert-success',
    'warning' => 'alert-warning',
  );

  foreach ($variables['messages'] as $type => &$messages) {
    $messages['#attributes']['class'][] = 'alert';
    $messages['#attributes']['class'][] = $status_mapping[$type];
    $messages['value']['#attributes']['class'][] = 'list-unstyled';
  }
}
