<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_update_status_label(array $existing, $type, $theme, $path) {
  return array(
    'update_status_label' => array(
      'template' => 'update-status-label',
      'variables' => array('status' => NULL),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_update_status_label() {
  return array(
    'label' => 'Update status label',
    'description' => 'Update status label description.',
    'dependencies' => array(
      'update',
    ),
    'preview' => array(),
  );
}

/**
 * Implements hook_atomium_definition_form_hook().
 */
function atomium_atomium_definition_form_update_status_label(array $form, array &$form_state) {
  $statuses = array(
    UPDATE_CURRENT,
    UPDATE_NOT_CURRENT,
    UPDATE_NOT_SECURE,
    UPDATE_NOT_SUPPORTED,
    UPDATE_REVOKED,
  );

  foreach ($statuses as $status) {
    $form['status-' . $status] = array(
      '#theme' => 'update_status_label',
      '#status' => $status,
    );
  }

  return $form;
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_update_status_label(array &$variables, $hook) {
  $text = '';
  $class = '';

  switch ($variables['status']) {
    case UPDATE_NOT_SECURE:
      $class = 'security-error';
      $text = t('Security update required!');

      break;

    case UPDATE_REVOKED:
      $class = 'revoked';
      $text = t('Revoked!');

      break;

    case UPDATE_NOT_SUPPORTED:
      $class = 'not-supported';
      $text = t('Not supported!');

      break;

    case UPDATE_NOT_CURRENT:
      $class = 'not-current';
      $text = t('Update available');

      break;

    case UPDATE_CURRENT:
      $class = 'current';
      $text = t('Up to date');

      break;
  }

  $variables['atomium']['attributes']['wrapper']->append('class', $class);
  $variables[$variables['base_hook']] = $text;
}
