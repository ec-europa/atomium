<?php

/**
 * @file
 * Contains element file.
 *
 * This custom element is based on the textarea element from Drupal core.
 *
 * The differences are:
 *  - It render the children element if any,
 *  - Extend #theme key based on suggestions in #theme_hook_suggestions_parts.
 */

/**
 * Implements hook_atomium_element_info_hook().
 */
function atomium_atomium_element_info_atomium_textarea(array $types) {
  $textarea = $types['textarea'];

  $textarea += array('#pre_render' => array());

  array_unshift(
    $textarea['#pre_render'], 'atomium_pre_render_children'
  );

  $textarea['#pre_render'][] = 'atomium_pre_render_extend_theme_property';

  return array(
    'atomium_textarea' => $textarea,
  );
}
