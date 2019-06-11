<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_pager_previous(array $existing, $type, $theme, $path) {
  return array(
    'pager_previous' => array(
      'template' => 'pager-previous',
      'variables' => array(
        'text' => '‹ previous',
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
function atomium_atomium_definition_pager_previous() {
  return array(
    'label' => 'Pager previous',
    'description' => 'Pager previous description',
    'preview' => array(
      'text' => '‹ previous',
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
function atomium_preprocess_pager_previous(array &$variables, $hook) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array;
  $pager_previous = NULL;

  // If we are anywhere but the first page.
  if ($pager_page_array[$element] > 0) {
    $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);

    // If the previous page is the first page, mark the link as such.
    if ($page_new[$element] === 0) {
      $pager_previous = array(
        '#theme' => _atomium_extend_theme_hook(
          'pager_first',
          array($variables['theme_hook_original'])
        ),
        '#text' => $text,
        '#element' => $element,
        '#parameters' => $parameters,
        '#attributes' => $attributes,
      );
    }
    // The previous page is not the first page.
    else {
      $pager_previous = array(
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
    $variables['base_hook'] => $pager_previous,
  );
}
