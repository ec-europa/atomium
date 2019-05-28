<?php

/**
 * @file
 * Contains element file.
 *
 * This custom element is based on the html_tag element from Drupal core.
 * The origin of this element comes from a discussion on drupal.org and the use
 * of html_tag element.
 *
 * @see https://www.drupal.org/project/drupal/issues/2981726
 *
 * The differences are:
 *  - It render the children element if any,
 *  - It ensure that the '#tag' is plain text
 *  - Automatically uses a void element (hr, img, etc etc...)
 *  - Extend #theme key based on suggestions in #theme_hook_suggestions_parts
 */

/**
 * Implements hook_atomium_element_info_hook().
 */
function atomium_atomium_element_info_atomium_actions(array $types) {
  $actions = $types['actions'];

  $actions['#theme'] = 'actions';

  $actions += array('#pre_render' => array());

  array_unshift(
    $actions['#pre_render'], 'atomium_pre_render_children'
  );
  $actions['#pre_render'][] = 'atomium_pre_render_extend_theme_property';

  return array(
    'atomium_actions' => $actions,
  );
}
