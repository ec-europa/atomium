<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_menu_link() {
  return array(
    'menu_link' => array(
      'render element' => 'element',
      'template' => 'menu-link',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_menu_link(&$variables, $hook) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = $element['#below'];
  }

  $variables['attributes_array'] = drupal_array_merge_deep($element['#attributes'], $variables['attributes_array']);
  $variables['sub_menu'] = $sub_menu;
  $variables['output'] = array(
    '#theme' => 'link__' . $variables['theme_hook_original'],
    '#text' => $element['#title'],
    '#path' => $element['#href'],
    '#options' => $element['#localized_options'],
    '#context' => array(
      'parents' => array(
        $hook => $variables,
      ),
    ),
  );

  if (isset($variables['element']['#original_link']['mlid'])) {
    $variables['theme_hook_suggestions'][] = 'menu_link__' . $variables['element']['#original_link']['mlid'];
  }
}
