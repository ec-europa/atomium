<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
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
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_breadcrumb() {
  return array(
    'label' => 'Breadcrumb',
    'description' => 'Site breadcrumb.',
    'preview' => array(
      'breadcrumb' => array(
        array(
          '#theme' => _atomium_extend_theme_hook('link'),
          '#text' => 'Home',
          '#path' => '/',
        ),
        array(
          '#theme' => _atomium_extend_theme_hook('link'),
          '#text' => 'News',
          '#path' => '/',
        ),
        t('My news title'),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_breadcrumb(array &$variables, $hook) {
  $links = array();
  foreach ($variables['breadcrumb'] as $item) {
    if (is_string($item)) {
      $item = array(
        '#markup' => $item,
      );
    }

    $links[] = array(
      'link' => $item,
      '#theme_wrappers' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original'] . '__li'),
      '#tag' => 'li',
    );
  }

  $variables['breadcrumb'] = '';
  if ($links) {
    $variables[$variables['base_hook']] = array(
      $variables['base_hook'] => array(
        '#theme' => _atomium_extend_theme_hook('item_list', $variables['theme_hook_original']),
        '#items' => $links,
        '#type' => 'ul',
        '#wrapper' => FALSE,
        '#attributes' => array(),
      ),
    );
  }
}
