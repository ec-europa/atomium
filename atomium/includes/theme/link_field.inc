<?php

/**
 * @file
 * link_field.inc
 */

/**
 * Implements hook_link_field().
 */
function atomium_link_field($vars) {
  drupal_add_css(drupal_get_path('module', 'link') . '/link.css');

  $element = $vars['element'];
  // Prefix single value link fields with the name of the field.
  if (empty($element['#field']['multiple'])) {
    if (isset($element['url']) && !isset($element['title'])) {
      unset($element['url']['#title']);
    }
  }

  // Placeholder.
  $element['#attributes']['placeholder'] = $element['#title'];

  $output = '';
  // $output .= '<div class="link-field-subrow">WTF';.
  if (!empty($element['attributes']['target'])) {
    $output .= '<div class="link-attributes">' . drupal_render($element['attributes']['target']) . '</div>';
  }
  if (!empty($element['attributes']['title'])) {
    $output .= '<div class="link-attributes">' . drupal_render($element['attributes']['title']) . '</div>';
  }
  // $output .= '</div>';.
  return $output;
}
