<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_date(array $existing, $type, $theme, $path) {
  return array(
    'date' => array(
      'render element' => 'element',
      'template' => 'date',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_date() {
  return array(
    'label' => 'Date',
    'description' => 'Date description.',
    'preview' => array(
      'element' => array(
        array(
          '#markup' => format_date(REQUEST_TIME),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_date(array &$variables, $hook) {
  $element = $variables['element'];

  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = (array) $element['#attributes']['class'];
  }
  $attributes['class'][] = 'container-inline';
  $variables['date'] = $variables['element'];
  $variables['atomium']['attributes']['wrapper']->merge($attributes);
}
