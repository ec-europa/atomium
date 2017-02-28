<?php

/**
 * @file
 * status_messages.inc
 */

/**
 * Implements hook_status_messages().
 */
function atomium_foundation_status_messages($variables) {
  $display = $variables['display'];

  $status_mapping = array(
    'error' => 'alert',
    'status' => 'success',
    'warning' => 'warning',
  );

  $output = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(),
    ),
    'messages' => array(),
  );

  $close = array(
    '#theme' => 'html_tag',
    '#tag' => 'button',
    '#attributes' => array(
      'type' => 'button',
      'class' => array(
        'close-button',
      ),
      'aria-label' => t('Dismiss alert'),
      'data-close',
    ),
    '#value' => '',
    'value' => array(
      '#theme' => 'html_tag',
      '#tag' => 'span',
      '#attributes' => array(
        'aria-hidden' => 'true',
      ),
      '#value' => '&times;'
    ),
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $container = array(
      '#type' => 'container',
      array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#attributes' => array(
          'data-closable' => '',
          'class' => array(
            'data-closable',
            'callout',
            isset($status_mapping[$type]) ? $status_mapping[$type] : 'info',
          ),
        ),
      ),
    );

    $item_list = array(
      '#theme' => 'item_list',
      '#items' => $messages,
      '#type' => 'ul',
      '#attributes' => array('class' => array('no-bullet')),
    );
    $container[0]['#value'] = render($item_list) . render($close);

    $output['messages'][] = $container;
  }

  if (empty($output['messages'])) {
    $output = array();
  }

  return render($output);
}
