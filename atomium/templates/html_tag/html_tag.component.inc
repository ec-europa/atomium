<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_html_tag() {
  return array(
    'html_tag' => array(
      'render element' => 'element',
      'template' => 'html-tag',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_html_tag(array &$variables, $hook) {
  $element = &$variables['element'];

  // Loop over element children, render them, and add them to the #value string.
  foreach (element_children($variables['element']) as $key) {
    if (isset($variables['element']['#value']) && $variables['element']['#value'] === NULL) {
      // Set this to string to avoid E_NOTICE error when concatenating to NULL.
      $variables['element']['#value'] = array();
    }
    // Concatenate the rendered child onto the element #value.
    $variables['element']['#value'][] = $variables['element'][$key];
  }

  if (!empty($variables['element']['#atomium']['attributes'])) {
    foreach ($variables['element']['#atomium']['attributes'] as $attribute => $data) {
      $variables['atomium']['attributes'][$attribute]->setAttributes($data);
    }
  }
  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  $variables['atomium']['attributes']['element']->merge($variables['element']['#attributes']);

  if (isset($variables['element']['#tag'])) {
    $variables['theme_hook_suggestions'][] = 'html_tag__' . $variables['element']['#tag'];
  }

  $element += array('#value' => '', '#children' => '');

  // Remove type="..." and CDATA prefix/suffix.
  unset($element['#attributes']['type'], $element['#value_prefix'], $element['#value_suffix']);

  // Remove media="all" but leave others unaffected.
  if (isset($element['#attributes']['media']) && $element['#attributes']['media'] === 'all') {
    unset($element['#attributes']['media']);
  }
}
