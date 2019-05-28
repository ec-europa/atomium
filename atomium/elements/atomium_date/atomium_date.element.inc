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
function atomium_atomium_element_info_atomium_date(array $types) {
  $date = $types['date'];

  $date += array('#pre_render' => array());

  array_unshift(
    $date['#pre_render'], 'atomium_pre_render_children'
  );

  $date['#pre_render'][] = 'atomium_pre_render_extend_theme_property';

  return array(
    'atomium_date' => $date,
  );
}
