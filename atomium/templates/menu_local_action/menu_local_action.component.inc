<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_local_action(array $existing, $type, $theme, $path) {
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
    $variables[$variables['base_hook']] = array(
      '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
      '#text' => $link['title'],
      '#path' => $link['href'],
      '#options' => array(),
    );
  }
  elseif (!empty($link['localized_options']['html'])) {
    $variables[$variables['base_hook']] = $link['title'];
  }
  else {
    $variables[$variables['base_hook']] = check_plain($link['title']);
  }
}
