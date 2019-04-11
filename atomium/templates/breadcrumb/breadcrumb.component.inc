<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_breadcrumb(array $existing, $type, $theme, $path) {
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
          '#theme' => 'link',
          '#text' => 'Home',
          '#path' => '/',
        ),
        array(
          '#theme' => 'link',
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
    if (\is_string($item)) {
      $item = array(
        '#markup' => $item,
      );
    }

    $link = array(
      'link' => $item,
      '#theme_wrappers' => _atomium_extend_theme_hook(
        'html_tag',
        array(
          'li',
          $variables['theme_hook_original'],
        )
      ),
      '#tag' => 'li',
    );

    $links[] = $link;
  }

  $breadcrumb = array();

  if (!empty($links)) {
    $breadcrumb = array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        array(
          'ul',
          $variables['theme_hook_original'],
        )
      ),
      '#items' => $links,
      '#type' => 'ul',
      '#wrapper' => FALSE,
      '#attributes' => array(),
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $breadcrumb,
  );
}
