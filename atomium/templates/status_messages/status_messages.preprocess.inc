<?php

/**
 * @file
 * status_messages.preprocess.inc
 */

/**
 * Implements hook_preprocess_status_messages().
 */
function atomium_preprocess_status_messages(&$variables) {
  $display = $variables['display'];

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );

  $output = array();
  foreach (drupal_get_messages($display) as $type => $messages) {
    $container = array(
      '#type' => 'container',
      array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#attributes' => array(
          'class' => array(
            isset($status_mapping[$type]) ? $status_mapping[$type] : 'info',
          ),
        ),
      ),
    );

    $item_list = array(
      '#theme' => 'item_list',
      '#title' => !empty($status_heading[$type]) ? $status_heading[$type] : '',
      '#items' => $messages,
      '#type' => 'ul',
      '#attributes' => array('class' => array()),
    );
    $container[0]['#value'] = $item_list;

    $output[] = $container;
  }

  $variables['messages'] = $output;
}
