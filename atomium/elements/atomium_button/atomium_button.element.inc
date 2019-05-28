<?php

/**
 * @file
 * Contains element file.
 *
 * This custom element is based on the date element from Drupal core.
 *
 * The differences are:
 *  - It render the children element if any,
 *  - Extend #theme key based on suggestions in #theme_hook_suggestions_parts.
 */

/**
 * Implements hook_atomium_element_info_hook().
 */
function atomium_atomium_element_info_atomium_button(array $types) {
  $button = $types['button'];

  $button += array('#pre_render' => array());

  array_unshift(
    $button['#pre_render'], 'atomium_pre_render_children_input'
  );

  $button['#pre_render'][] = 'atomium_pre_render_extend_theme_property';

  return array(
    'atomium_button' => $button,
  );
}

/**
 * Custom pre_render callback.
 *
 * @param array $element
 *   The element to alter.
 *
 * @return array
 *   The element altered.
 */
function atomium_pre_render_children_input(array $element) {
  $element += array(
    '#value' => '',
  );

  // We concatenate the #value key to remain completely compatible with the
  // 'html_tag' core type.
  $element['#value'] .= drupal_render_children($element);

  return $element;
}
