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
    if (is_string($item)) {
      $item = array(
        '#markup' => $item,
      );
    }

    $links[] = array(
      'link' => $item,
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'li',
    );
  }

  array_walk($links, function (&$link) use ($variables) {
    _atomium_extend_theme_wrappers_property(
      $link,
      array($link['#tag'], $variables['theme_hook_original']));
  });

  $variables['breadcrumb'] = '';
  if ($links) {
    $breadcrumb = array(
      '#theme' => 'item_list',
      '#items' => $links,
      '#type' => 'ul',
      '#wrapper' => FALSE,
      '#attributes' => array(),
    );

    _atomium_extend_theme_property(
      $breadcrumb,
      array($breadcrumb['#type'], $variables['theme_hook_original']));

    $variables[$variables['base_hook']] = array(
      $variables['base_hook'] => $breadcrumb,
    );
  }
}
