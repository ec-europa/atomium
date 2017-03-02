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
    $messages['#attributes']['class'][] = 'alert-dismissible';
    $messages['#attributes']['class'][] = $status_mapping[$type];
    $messages['value']['#attributes']['class'][] = 'list-unstyled';

    // Small trick to have the close button before the value in the array.
    $value = $messages['value'];
    unset($messages['value']);

    // This is the only place where there is HTML.
    $messages['close'] = array(
      '#markup' => '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span></button>',
    );
    $messages['value'] = $value;

  }
}
