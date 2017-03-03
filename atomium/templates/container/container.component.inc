<?php

/**
 * @file
 * Container.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__container() {
  return array(
    'container' => array(
      'render element' => 'element',
      'template' => 'container',
    ),
  );
}

/**
 * Implements hook_preprocess_container().
 */
function atomium_preprocess_container(&$variables) {
  $element = $variables['element'];
  // Ensure #attributes is set.
  $element += array('#attributes' => array());

  // Special handling for form elements.
  if (isset($element['#array_parents'])) {
    // Assign an html ID.
    if (!isset($element['#attributes']['id'])) {
      $element['#attributes']['id'] = $element['#id'];
    }
    // Add the 'form-wrapper' class.
    $element['#attributes']['class'][] = 'form-wrapper';
  }

  $variables['attributes_array'] = $element['#attributes'];
}
