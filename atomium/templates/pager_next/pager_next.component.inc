<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_next(array $existing, $type, $theme, $path) {
  return array(
    'pager_next' => array(
      'template' => 'pager-next',
      'variables' => array(
        'text' => NULL,
        'element' => 0,
        'interval' => 1,
        'parameters' => array(),
        'attributes' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_pager_next() {
  return array(
    'label' => 'Pager next',
    'description' => 'Pager next description',
    'preview' => array(
      'text' => 'next ›',
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
function atomium_preprocess_pager_next(array &$variables, $hook) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array, $pager_total;
  $pager_next = NULL;

  // If we are anywhere but the last page.
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
    // If the next page is the last page, mark the link as such.
    if ($page_new[$element] === ($pager_total[$element] - 1)) {
      $pager_next = array(
        '#theme' => _atomium_extend_theme_hook(
        'pager_last',
        array($variables['theme_hook_original'])
        ),
        '#text' => $text,
        '#element' => $element,
        '#parameters' => $parameters,
        '#attributes' => $attributes,
      );
    }
    // The next page is not the last page.
    else {
      $pager_next = array(
        '#theme' => _atomium_extend_theme_hook(
          'pager_link',
          array($variables['theme_hook_original'])
        ),
        '#text' => $text,
        '#page_new' => $page_new,
        '#element' => $element,
        '#parameters' => $parameters,
        '#attributes' => $attributes,
      );
    }
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $pager_next,
  );
}
