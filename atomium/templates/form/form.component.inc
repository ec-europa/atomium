<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_form() {
  return array(
    'form' => array(
      'render element' => 'element',
      'template' => 'form',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_form(&$variables) {
  $variables['theme_hook_suggestions'][] = 'form--' . $variables['element']['#form_id'];
}
