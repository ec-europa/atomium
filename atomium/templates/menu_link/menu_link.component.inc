<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_link(array $existing, $type, $theme, $path) {
  return array(
    'menu_link' => array(
      'render element' => 'element',
      'template' => 'menu-link',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_link(array &$variables, $hook) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = $element['#below'];
  }

  // Ensure "html" is now enabled so l() doesn't double encode. This is now
  // safe to do since both check_plain() and filter_xss_admin() encode HTML
  // entities. See: https://www.drupal.org/node/2854978
  $element['#localized_options']['html'] = TRUE;

  $variables['atomium']['attributes']['wrapper']->merge($element['#attributes']);

  $menu_link = array(
    '#theme' => 'link',
    '#text' => empty($element['#localized_options']['html']) ? check_plain($element['#title']) : filter_xss_admin($element['#title']),
    '#path' => $element['#href'],
    '#options' => $element['#localized_options'] + array('attributes' => array()),
  );

  _atomium_extend_theme_property(
    $menu_link,
    array($variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $menu_link,
  );
  $variables['submenu'] = array(
    'submenu' => $sub_menu,
  );
}
