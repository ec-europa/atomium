<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_breadcrumb() {
  return array(
    'breadcrumb' => array(
      'variables' => array('breadcrumb' => NULL),
      'template' => 'breadcrumb',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_breadcrumb(&$variables, $hook) {
  foreach ($variables['breadcrumb'] as $key => $item) {
    if (is_string($item)) {
      $variables['breadcrumb'][$key] = array(
        '#markup' => $item,
      );
    }

    $variables['breadcrumb'][$key]['#theme_wrappers'] = array('html_tag__' . $variables['theme_hook_original']);
    $variables['breadcrumb'][$key]['#tag'] = 'li';
  }

  $variables['wrapper_attributes_array'] = $variables['attributes_array'];

  $variables[$hook] = array(
    $hook => array(
      '#theme' => 'item_list',
      '#items' => $variables['breadcrumb'],
      '#type' => 'ul',
      '#wrapper' => FALSE,
      '#attributes' => $variables['attributes_array'],
    ),
    '#theme_wrappers' => array('html_tag'),
    '#tag' => 'nav',
    '#attributes' => $variables['wrapper_attributes_array'],
  );
}
