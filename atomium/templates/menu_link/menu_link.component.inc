<?php

/**
 * @file
 * Menu_link.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__menu_link() {
  return array(
    'menu_link' => array(
      'render element' => 'element',
      'template' => 'menu-link',
    ),
  );
}

/**
 * Implements hook_preprocess_menu_link().
 */
function atomium_preprocess_menu_link(&$variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = $element['#below'];
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  $variables['attributes_array'] = drupal_array_merge_deep($element['#attributes'], $variables['attributes_array']);
  $variables['sub_menu'] = $sub_menu;
  $variables['output'] = $output;

  if (isset($variables['element']['#original_link']['mlid'])) {
    $variables['theme_hook_suggestions'][] = 'menu_link__' . $variables['element']['#original_link']['mlid'];
  }
}
