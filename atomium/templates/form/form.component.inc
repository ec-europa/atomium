<?php

/**
 * @file
 * Form.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__form() {
  return array(
    'form' => array(
      'render element' => 'element',
      'template' => 'form',
    ),
  );
}

/**
 * Implements hook_preprocess_form().
 */
function atomium_preprocess_form(&$variables) {
  $variables['theme_hook_suggestions'][] = 'form--' . $variables['element']['#form_id'];
}
