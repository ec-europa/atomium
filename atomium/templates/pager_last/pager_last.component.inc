<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_last(array $existing, $type, $theme, $path) {
  return array(
    'pager_last' => array(
      'template' => 'pager-last',
      'variables' => array(
        'text' => NULL,
        'element' => 0,
        'interval' => 1,
        'parameters' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager_last() {
  return array(
    'label' => 'Pager last',
    'description' => 'Pager last description',
    'preview' => array(
      'text' => 'last »',
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
function atomium_preprocess_pager_last(array &$variables, $hook) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  global $pager_page_array, $pager_total;
  $render = NULL;

  $pager_last = NULL;

  // If we are anywhere but the last page.
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $pager_last = array(
      '#theme' => 'pager_link',
      '#text' => $text,
      '#page_new' => pager_load_array($pager_total[$element] - 1, $element, $pager_page_array),
      '#element' => $element,
      '#parameters' => $parameters,
    );

    _atomium_extend_theme_property(
      $pager_last,
      array($variables['theme_hook_original'])
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $pager_last,
  );
}
