<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_container() {
  return array(
    'container' => array(
      'render element' => 'element',
      'template' => 'container',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_container(array &$variables, $hook) {
  $element = $variables['element'];

  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  // Doing this to remove warnings.
  $element += array(
    '#attributes' => array(),
  );

  // Special handling for form elements.
  if (isset($element['#array_parents'])) {
    // Assign an html ID.
    $variables['atomium']['attributes']['wrapper']->setAttribute('id', $element['#id']);
  }
  $variables['container'] = $element['#children'];

  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  $variables['atomium']['attributes']['wrapper']->merge($element['#attributes']);
}
