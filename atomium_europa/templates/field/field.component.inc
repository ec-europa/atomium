<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_europa_atomium_definition_field() {
  return array(
    'label' => 'Field',
    'description' => 'Field.',
    'preview' => array(
      'label_display' => TRUE,
      'field_name' => 'my_field',
      'field_type' => 'textfield',
      'bundle' => 'page',
      'label' => 'Label',
      'items' => array(
        array(
          '#markup' => 'Item 1',
        ),
        array(
          '#markup' => 'Item 2',
        ),
      ),
      array(
        '#markup' => 'Item 1',
      ),
      array(
        '#markup' => 'Item 2',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_europa_preprocess_field(&$variables) {
  if (isset($variables['element']['#label'])) {
    $variables['label'] = $variables['element']['#label'];
  }
}
