<?php

/**
 * @file
 * Status_messages.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_status_messages(&$variables, $hook) {
  $status_mapping = array(
    'error' => 'alert-danger',
    'status' => 'alert-success',
    'warning' => 'alert-warning',
  );

  foreach ($variables[$hook][$hook] as $type => &$messages) {
    $messages['#attributes']['class'][] = 'alert';
    $messages['#attributes']['class'][] = 'alert-dismissible';
    $messages['#attributes']['class'][] = $status_mapping[$type];
    $messages['value']['#attributes']['class'][] = 'list-unstyled';

    $messages['close'] = array(
      '#name' => 'close-button',
      '#type' => 'button',
      '#attributes' => array(
        'class' => array(
          'close',
        ),
        'aria-label' => t('Dismiss alert'),
        'data-dismiss' => 'alert',
      ),
      'value' => array(
        '#markup' => '&times;',
        '#theme_wrappers' => array('html_tag'),
        '#tag' => 'span',
        '#attributes' => array(
          'class' => array(
            'aria-hidden' => 'true',
          ),
        ),
      ),
      '#weight' => -1,
    );
  }
}
