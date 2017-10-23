<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_form_required_marker() {
  return array(
    'form_required_marker' => array(
      'template' => 'form-required-marker',
      'variables' => array(
        'title' => '*',
      ),
    ),
  );
}
