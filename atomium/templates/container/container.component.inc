<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
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
 * Implements hook_preprocess_HOOK().
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

  $variables[$hook] = array(
    $hook => array(
      '#markup' => $variables['element']['#children'],
    ),
    '#theme_wrappers' => array('html_tag'),
    '#tag' => 'div',
    '#attributes' => $element['#attributes'],
  );
}
