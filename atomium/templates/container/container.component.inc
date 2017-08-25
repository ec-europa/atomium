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
function atomium_preprocess_container(&$variables, $hook) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += array('#attributes' => array());

  // Special handling for form elements.
  if (isset($element['#array_parents'])) {
    // Assign an html ID.
    if (!isset($element['#attributes']['id'])) {
      $element['#attributes']['id'] = $element['#id'];
    }
  }

  $variables['attributes_array'] = $element['#attributes'];
  $variables['container'] = $element['#children'];

  // Ensure $attributes_array['class'] is set and an array.
  $variables['attributes_array'] += array('class' => array());
  if (!is_array($variables['attributes_array']['class'])) {
    $variables['attributes_array']['class'] = array($variables['attributes_array']['class']);
  }

  // If this is not added, it will cause issue with the #states mechanisms.
  // Especially in the theme settings form.
  $variables['attributes_array']['class'][] = 'form-wrapper';
}
