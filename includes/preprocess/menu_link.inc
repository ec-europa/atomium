<?php

/**
 * @file
 * menu_link.inc
 */

/**
 * Implements hook_preprocess_menu_link().
 */
function atomium_preprocess_menu_link(&$variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  $variables['attributes_array'] = $element['#attributes'];
  $variables['sub_menu'] = $sub_menu;
  $variables['output'] = $output;

  if (isset($variables['element']['#original_link']['mlid'])) {
    $variables['theme_hook_suggestions'][] = 'menu_link__' . $variables['element']['#original_link']['mlid'];
  }
}
