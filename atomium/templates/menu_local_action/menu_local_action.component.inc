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
function atomium_preprocess_menu_local_action(&$variables, $hook) {
  $link = $variables['link'];

  if (isset($link['href'])) {
    $variables['menu_link'] = array(
      '#theme' => 'link__' . $variables['theme_hook_original'],
      '#text' => $link['title'],
      '#path' => $link['href'],
      '#options' => isset($link['localized_options']) ? $link['localized_options'] : array('attributes' => array()),
      '#context' => array(
        'parents' => array(
          $hook => $variables,
        ),
      ),
    );
  }
  elseif (!empty($link['localized_options']['html'])) {
    $variables['menu_link'] = $link['title'];
  }
  else {
    $variables['menu_link'] = check_plain($link['title']);
  }

  $variables[$hook] = array(
    $hook => $variables['menu_link'],
    '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original']),
    '#tag' => 'li',
    '#attributes' => $variables['attributes_array'],
  );
}
