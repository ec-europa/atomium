<?php

/**
 * @file
 * fieldset.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__fieldset() {
  return array(
    'fieldset' => array(
      'render element' => 'element',
      'template' => 'fieldset',
    ),
  );
}
