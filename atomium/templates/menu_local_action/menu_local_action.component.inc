<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
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
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_menu_local_action(&$variables, $hook) {
  $link = $variables['element']['#link'];

  if (isset($link['href'])) {
    $variables['menu_link'] = array(
      '#theme' => 'link',
      '#text' => $link['title'],
      '#path' => $link['href'],
      '#options' => isset($link['localized_options']) ? $link['localized_options'] : array('attributes' => array()),
    );
  }
  elseif (!empty($link['localized_options']['html'])) {
    $variables['menu_link'] = $link['title'];
  }
  else {
    $variables['menu_link'] = check_plain($link['title']);
  }

  $variables[$hook] = array(
    $hook => array(
      $variables['menu_link'],
    ),
    '#theme_wrappers' => array('html_tag'),
    '#tag' => 'li',
    '#attributes' => $variables['attributes_array'],
  );
}
