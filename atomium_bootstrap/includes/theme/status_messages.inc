<?php

/**
 * @file
 * status_messages.inc
 */

/**
 * Implements hook_status_messages().
 */
function atomium_bootstrap_status_messages($variables) {
  $display = $variables['display'];

  $status_mapping = array(
    'status' => 'success',
    'error' => 'danger',
    'warning' => 'warning',
  );

  $output = array();
  foreach (drupal_get_messages($display) as $type => $messages) {
    $container = array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#attributes' => array(
        'class' => array(
          'alert',
          'alert-block',
          'messages',
          $type,
          isset($status_mapping[$type]) ? 'alert-' . $status_mapping[$type] : 'alert-info',
        ),
      ),
    );

    if (count($messages) > 1) {
      $item_list = array(
        '#theme' => 'item_list',
        '#items' => $messages,
        '#type' => 'ul',
        '#attributes' => array('class' => array('list-unstyled')),
      );
      $container['#value'] = render($item_list);
    }
    else {
      $container['#value'] = $messages[0];
    }

    $output[] = $container;
  }

  return render($output);
}
