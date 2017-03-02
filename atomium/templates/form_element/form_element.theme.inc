<?php

/**
 * @file
 * form_element.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__form_element() {
  return array(
    'form_element' => array(
      'template' => 'form-element',
      'render element' => 'element',
    ),
  );
}
