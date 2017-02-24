<?php

/**
 * @file
 * html_tag.inc
 */

/**
 * Implements hook_preprocess_html_tag().
 */
function atomium_preprocess_html_tag(&$variables) {
  $element = &$variables['element'];

  // Loop over element children, render them, and add them to the #value string.
  foreach (element_children($variables['element']) as $key) {
    if ($variables['element']['#value'] === NULL) {
      // Set this to string to avoid E_NOTICE error when concatenating to NULL.
      $variables['element']['#value'] = '';
    }
    // Concatenate the rendered child onto the element #value.
    $variables['element']['#value'] .= drupal_render($variables['element'][$key]);
  }

  $variables['attributes_array'] = $variables['element']['#attributes'];

  if (isset($variables['element']['#tag'])) {
    $variables['theme_hook_suggestions'][] = 'html_tag__' . $variables['element']['#tag'];
  }

  $element += array('#value' => '');
}
