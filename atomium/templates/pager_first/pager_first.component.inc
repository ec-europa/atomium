<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_first(array $existing, $type, $theme, $path) {
  return array(
    'pager_first' => array(
      'template' => 'pager-first',
      'variables' => array(
        'text' => NULL,
        'element' => 0,
        'parameters' => array(),
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager_first() {
  return array(
    'label' => 'Pager first',
    'description' => 'Pager first description',
    'preview' => array(
      'text' => '« first',
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
function atomium_preprocess_pager_first(array &$variables, $hook) {
  global $pager_page_array;

  $text = $variables['text'];
  $element = $variables['element'];

  $pager_first = NULL;

  // If we are anywhere but the first page.
  if ($pager_page_array[$element] > 0) {
    $pager_first = array(
      '#theme' => 'pager_link',
      '#text' => $text,
      '#page_new' => pager_load_array(0, $element, $pager_page_array),
      '#element' => $element,
      '#parameters' => $variables['parameters'],
      '#attributes' => $variables['attributes'],
    );

    _atomium_extend_theme_property(
      $pager_first,
      array($variables['theme_hook_original'])
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $pager_first,
  );
}
