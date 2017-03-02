<?php

/**
 * @file
 * menu_local_action.preprocess.inc
 */

/**
 * Implements hook_preprocess_menu_local_action().
 */
function atomium_preprocess_menu_local_action(&$variables) {
  $link = $variables['element']['#link'];

  if (isset($link['href'])) {
    $variables['menu_link'] = array(
      '#theme' => 'link',
      '#text' => $link['title'],
      '#path' => $link['href'],
      '#options' => isset($link['localized_options']) ? $link['localized_options'] : array(),
    );
  }
  elseif (!empty($link['localized_options']['html'])) {
    $variables['menu_link'] = $link['title'];
  }
  else {
    $variables['menu_link'] = check_plain($link['title']);
  }
}
