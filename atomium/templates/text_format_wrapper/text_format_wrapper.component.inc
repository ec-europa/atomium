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
function atomium_preprocess_text_format_wrapper(array &$variables, $hook) {
  $element = $variables['element'];

  $text_format_wrapper = array(
    'children' => array(
      '#markup' => $element['#children'],
      '#weight' => 5,
    ),
    '#theme_wrappers' => array('html_tag'),
    '#tag' => 'div',
    '#attributes' => array(
      'class' => array(
        'text-format-wrapper',
      ),
    ),
  );

  _atomium_extend_theme_wrappers_property(
    $text_format_wrapper,
    array($text_format_wrapper['#tag'], $variables['theme_hook_original']));

  $description = array();
  if (!empty($element['#description'])) {
    $description = array(
      'description' => array(
        '#markup' => $element['#description'],
        '#weight' => 10,
        '#theme_wrappers' => array('html_tag'),
        '#tag' => 'div',
        '#attributes' => array(
          'class' => array(
            'text-format-wrapper',
          ),
        ),
      ),
    );

    _atomium_extend_theme_wrappers_property(
      $description['description'],
      array($description['description']['#tag'], $variables['theme_hook_original']));
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $text_format_wrapper + $description,
  );
}
