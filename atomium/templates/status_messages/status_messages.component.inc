<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_status_messages() {
  return array(
    'status_messages' => array(
      'variables' => array('display' => NULL),
      'template' => 'status-messages',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
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
      '#attributes' => array(
        'class' => array(
          $type,
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
    $container['value'] = $item_list;

    $output[$type] = $container;
  }

  $variables['messages'] = $output;
}
