<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_text_format_wrapper() {
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
function atomium_preprocess_text_format_wrapper(&$variables, $hook) {
  $element = $variables['element'];

  $variables[$variables['base_hook']] = array(
    'children' => array(
      '#markup' => $element['#children'],
      '#weight' => 5,
    ),
    '#theme_wrappers' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array(
        'text-format-wrapper',
      ),
    ),
  );

  if (!empty($element['#description'])) {
    $variables[$variables['base_hook']] += array(
      'description' => array(
        '#markup' => $element['#description'],
        '#weight' => 10,
        '#theme_wrappers' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
        '#tag' => 'div',
        '#attributes' => array(
          'class' => array(
            'text-format-wrapper',
          ),
        ),
      ),
    );
  }
}
