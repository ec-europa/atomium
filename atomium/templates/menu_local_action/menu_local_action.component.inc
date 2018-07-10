<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_local_action() {
  return array(
    'menu_local_action' => array(
      'render element' => 'element',
      'template' => 'menu-local-action',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_local_action(array &$variables, $hook) {
  $link = $variables['element']['#link'];

  $link += array('localized_options' => array());
  $link['localized_options'] += array('attributes' => array());

  if (isset($link['href'])) {
    $menu_local_action = array(
      '#theme' => 'link',
      '#text' => $link['title'],
      '#path' => $link['href'],
      '#options' => array(),
    );
  }
  elseif (!empty($link['localized_options']['html'])) {
    $menu_local_action = $link['title'];
  }
  else {
    $menu_local_action = check_plain($link['title']);
  }

  _atomium_extend_theme_property(
    $menu_local_action,
    array($variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] = $menu_local_action,
  );
}
