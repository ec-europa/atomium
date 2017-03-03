<?php

/**
 * @file
 * Menu_local_action.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_menu_local_action() {
  return array(
    'menu_local_action' => array(
      'template' => 'menu-local-action',
      'variables' => array(
        'element' => NULL,
        'link' => NULL,
        'menu_link' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_menu_local_action(&$variables) {
  $link = $variables['link'];

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

}
