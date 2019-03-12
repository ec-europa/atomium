<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_form(array $existing, $type, $theme, $path) {
  return array(
    'form' => array(
      'render element' => 'element',
      'template' => 'form',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_form(array &$variables, $hook) {
  if (isset($variables['element']['#form_id'])) {
    $variables['theme_hook_suggestions'][] = 'form--' . $variables['element']['#form_id'];
  }

  $element = &$variables['element'];

  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = 'UTF-8';
  }

  $variables['atomium']['attributes']['element']->merge($element['#attributes']);
}
