<?php

/**
 * @file
 * button.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__button() {
  return array(
    'button' => array(
      'render element' => 'element',
      'template' => 'button',
    ),
  );
}

/**
 * Implements THEME_atomium_overview__HOOK().
 */
function atomium_atomium_overview__button() {
  return array(
    'label' => 'Button',
    'description' => 'Button template.',
    'preview' => array(
      'type' => 'submit',
      'value' => 'Save',
    ),
  );
}
