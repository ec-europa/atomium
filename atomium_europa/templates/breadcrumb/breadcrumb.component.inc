<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_europa_preprocess_breadcrumb(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'breadcrumb__segments-wrapper';

  foreach ($variables['breadcrumb']['breadcrumb']['#items'] as $key => $item) {
    $breadcrumb_items[] = array(
      '#markup' => $item,
      '#attributes' => array(
        'class' => array(
          'breadcrumb__segment',
        ),
      ),
    );
  }

  $variables[$hook] = array(
    'title' => array(
      '#markup' => t('You are here:'),
      '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original']),
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array(
          'sr-only',
        ),
      ),
    ),
    'breadcrumb' => array(
      '#theme' => 'item_list__' . $variables['theme_hook_original'],
      '#items' => $breadcrumb_items,
      '#type' => 'ol',
      '#wrapper' => FALSE,
      '#attributes' => $variables['attributes_array'],
    ),
    'suffix' => array(
      '#markup' => '...',
      '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original']),
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array(
          'breadcrumb__btn-separator',
        ),
        'style' => 'display: none;',
      ),
    ),
    '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original']),
    '#tag' => 'nav',
    '#attributes' => array(
      'class' => array(
        'breadcrumb',
      ),
      'role' => 'navigation',
      'aria-label' => 'breadcrumbs',
    ),
  );
}
