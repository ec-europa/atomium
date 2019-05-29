<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_text_format_wrapper(array $existing, $type, $theme, $path) {
  return array(
    'text_format_wrapper' => array(
      'render element' => 'element',
      'template' => 'text-format-wrapper',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_text_format_wrapper(array &$variables, $hook) {
  $element = $variables['element'];

  $variables[$variables['base_hook']] = array(
    '#type' => 'atomium_html_tag',
    '#tag' => 'div',
    '#theme_hook_suggestions_parts' => array(
      $variables['theme_hook_original'],
    ),
    '#attributes' => array(
      'class' => array(
        'text-format-wrapper',
      ),
    ),
    'children' => array(
      '#markup' => $element['#children'],
      '#weight' => 5,
    ),
  );

  if (!empty($element['#description'])) {
    $variables[$variables['base_hook']] += array(
      'description' => array(
        '#type' => 'atomium_html_tag',
        '#tag' => 'div',
        '#theme_hook_suggestions_parts' => array(
          $variables['theme_hook_original'],
        ),
        '#attributes' => array(
          'class' => array(
            'text-format-wrapper',
          ),
        ),
        '#weight' => 10,
        'value' => array(
          '#markup' => $element['#description'],
        ),
      ),
    );
  }
}
