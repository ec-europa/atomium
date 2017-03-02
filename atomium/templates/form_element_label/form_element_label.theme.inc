<?php

/**
 * @file
 * form_element_label.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__form_element_label() {
  return array(
    'form_element_label' => array(
      'template' => 'form-element-label',
      'variables' => array(
        'element' => NULL,
      ),
    ),
  );
}
