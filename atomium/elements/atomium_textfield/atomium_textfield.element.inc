<?php

/**
 * @file
 * Contains element file.
 *
 * This custom element is based on the textfield element from Drupal core.
 *
 * The differences are:
 *  - It render children elements if any into the #value property,
 *  - Extend #theme key based on suggestions in #theme_hook_suggestions_parts.
 */

/**
 * Implements hook_atomium_element_info_hook().
 */
function atomium_atomium_element_info_atomium_textfield(array $types) {
  $textfield = $types['textfield'];

  $textfield += array('#pre_render' => array());

  array_unshift(
    $textfield['#pre_render'], 'atomium_pre_render_children_input'
  );

  $textfield['#pre_render'][] = 'atomium_pre_render_extend_theme_property';

  return array(
    'atomium_textfield' => $textfield,
  );
}
