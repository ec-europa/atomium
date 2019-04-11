<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_link(array $existing, $type, $theme, $path) {
  return array(
    'pager_link' => array(
      'template' => 'pager-link',
      'variables' => array(
        'text' => NULL,
        'page_new' => NULL,
        'element' => NULL,
        'parameters' => array(),
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager_link() {
  return array(
    'label' => 'Pager link',
    'description' => 'Pager link description',
    'preview' => array(
      'text' => 'pager link',
      'element' => 0,
      'parameters' => array(
        'page' => 1,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_pager_link(array &$variables, $hook) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title.
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  $link = array(
    '#theme' => _atomium_extend_theme_hook(
      'link',
      array($variables['theme_hook_original'])
    ),
    '#text' => $text,
    '#path' => $_GET['q'],
    '#options' => array(
      'attributes' => $attributes,
      'query' => $query,
    ),
  );

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $link,
  );
}
