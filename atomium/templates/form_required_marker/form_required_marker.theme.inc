<?php

/**
 * @file
 * Form_element_mark.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__form_element_mark() {
  return array(
    'form_element_mark' => array(
      'render element' => 'element',
      'template' => 'form-required-marker',
      'variables' => array(
        'element' => NULL,
      ),
    ),
  );
}
