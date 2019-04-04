<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_file_managed_file(array $existing, $type, $theme, $path) {
  return array(
    'file_managed_file' => array(
      'template' => 'file-managed-file',
      'render element' => 'element',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_file_managed_file(array &$variables, $hook) {
  $element = $variables['element'];

  if (isset($element['#id'])) {
    $variables['atomium']['attributes']['wrapper']
      ->set('id', $element['#id']);
  }

  if (!empty($element['#attributes']['class'])) {
    $variables['atomium']['attributes']['wrapper']
      ->set('class', (array) $element['#attributes']['class']);
  }

  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'form-managed-file');
}
