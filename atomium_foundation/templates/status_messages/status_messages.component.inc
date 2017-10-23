<?php

/**
 * @file
 * Status_messages.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_status_messages(&$variables, $hook) {
  $status_mapping = array(
    'error' => 'alert',
    'status' => 'success',
    'warning' => 'secondary',
  );

  if (!empty($variables[$hook][$hook])) {
    foreach ($variables[$hook][$hook] as $type => &$messages) {
      $messages['#attributes'][] = 'data-closable';
      $messages['#attributes']['class'][] = 'callout';
      $messages['#attributes']['class'][] = isset($status_mapping[$type]) ? $status_mapping[$type] : $status_mapping['status'];
      $messages['value']['#attributes']['class'][] = 'no-bullet';

      $messages['close'] = array(
        '#name' => 'close-button',
        '#type' => 'button',
        '#attributes' => array(
          0 => 'data-close',
          'class' => array(
            'close-button',
          ),
          'aria-label' => t('Dismiss alert'),
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
      );
    }

    $variables[$hook][$hook]['#theme_wrappers'] = array('container');
  }
  else {
    $variables[$hook] = '';
  }
}
