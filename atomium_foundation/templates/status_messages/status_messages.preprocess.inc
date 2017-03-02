<?php

/**
 * @file
 * status_messages.preprocess.inc
 */

/**
 * Implements hook_preprocess_status_messages().
 */
function atomium_foundation_preprocess_status_messages(&$variables) {
  $status_mapping = array(
    'error' => 'alert',
    'status' => 'success',
    'warning' => 'secondary',
  );

  foreach ($variables['messages'] as $type => &$messages) {
    $messages['#attributes'][] = 'data-closable';
    $messages['#attributes']['class'][] = 'callout';
    $messages['#attributes']['class'][] = $status_mapping[$type];
    $messages['value']['#attributes']['class'][] = 'no-bullet';

    // This is the only place where there is HTML.
    $messages['close'] = array(
      '#markup' => '<button class="close-button" aria-label="Dismiss alert" type="button" data-close><span aria-hidden="true">&times;</span></button>',
    );
  }
}
