<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_europa_atomium_definition_breadcrumb() {
  return array(
    'label' => 'Breadcrumb',
    'description' => 'Site breadcrumb.',
    'preview' => array(
      'breadcrumb' => array(
        array(
          '#theme' => 'link',
          '#text' => t('Home'),
          '#href' => '/',
        ),
        array(
          '#theme' => 'link',
          '#text' => t('News'),
          '#href' => '/',
        ),
        array(
          '#theme' => 'link',
          '#text' => t('My news title'),
          '#href' => '/',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_europa_preprocess_breadcrumb(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'breadcrumb__segments-wrapper';
  $breadcrumb_items = array();

  foreach ($variables['breadcrumb']['breadcrumb']['#items'] as $key => $item) {
    if (isset($item['#text'])) {
      $item['#text'] = array(
        '#markup' => $item['#text'],
        '#theme_wrappers' => array('html_tag'),
        '#tag' => 'span',
        '#attributes' => array(
          'class' => array(
            'breadcrumb__text',
          ),
        ),
      );
    }

    $item['#options']['attributes']['class'][] = 'breadcrumb__link';
    $item['#attributes']['class'][] = 'breadcrumb__segment';

    $breadcrumb_items[] = $item;
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
