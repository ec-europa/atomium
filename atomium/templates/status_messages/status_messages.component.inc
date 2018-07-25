<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_status_messages() {
  return array(
    'status_messages' => array(
      'variables' => array(
        'display' => NULL,
        'messages' => array(),
      ),
      'template' => 'status-messages',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_status_messages() {
  return array(
    'label' => 'Status messages',
    'description' => 'Status messages.',
    'preview' => array(
      'messages' => array(
        'error' => array(
          t('Error message'),
        ),
        'status' => array(
          t('Status message'),
        ),
        'warning' => array(
          t('Warning message'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_status_messages(array &$variables, $hook) {
  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );

  $output = array();

  $variables += array('messages' => array());
  $status_messages = drupal_array_merge_deep($variables['messages'], drupal_get_messages($variables['display']));
  foreach ($status_messages as $type => $messages) {
    $container = array(
      'messages' => array(
        '#theme' => 'item_list',
        '#title' => !empty($status_heading[$type]) ? $status_heading[$type] : '',
        '#items' => $messages,
        '#type' => 'ul',
        '#attributes' => array('class' => array()),
      ),
      '#theme_wrappers' => array('container'),
      '#attributes' => array(
        'class' => array(
          $type,
        ),
      ),
    );

    _atomium_extend_theme_property(
      $container['messages'],
      array(
        $container['messages']['#type'],
        $type,
        $variables['theme_hook_original'],
      )
    );
    _atomium_extend_theme_wrappers_property(
      $container,
      array($container['messages']['#theme']));

    $output[$type] = $container;
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $output,
  );
}
