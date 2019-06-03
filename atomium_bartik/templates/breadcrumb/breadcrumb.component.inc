<?php

/**
 * @file
 * Breadcrumb.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_breadcrumb(array &$variables, $hook) {
  if (empty($variables['breadcrumb']['breadcrumb'])) {
    return;
  }

  $breadcrumb = array();

  foreach ($variables['breadcrumb']['breadcrumb']['#items'] as &$item) {
    $breadcrumb[] = $item;
    $breadcrumb[] = array(
      '#markup' => ' » ',
      '#theme_wrappers' => array(),
    );
  }

  \array_pop($breadcrumb);

  $variables['breadcrumb']['breadcrumb']['#items'] = $breadcrumb;
  $variables['breadcrumb']['#tag'] = 'div';
  $variables['breadcrumb']['#attributes']['id'] = 'breadcrumb';
  $variables['breadcrumb']['breadcrumb']['#type'] = 'div';
  $variables['breadcrumb']['breadcrumb']['#attributes']['class'][] = 'breadcrumb';
}
