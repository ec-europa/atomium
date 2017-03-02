<?php

/**
 * @file
 * form_element_mark.theme.inc
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
