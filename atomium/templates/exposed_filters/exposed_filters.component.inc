<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_exposed_filters(array $existing, $type, $theme, $path) {
  return array(
    'exposed_filters' => array(
      'render element' => 'form',
      'template' => 'exposed-filters',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_exposed_filters(array &$variables, $hook) {
  $form = $variables['form'];
  $exposed_filters = array();

  if (isset($form['current'])) {
    $items = array();

    foreach (element_children($form['current']) as $key) {
      $items[] = $form['current'][$key];
    }

    $exposed_filters = array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        array(
          $variables['theme_hook_original'],
        )
      ),
      '#items' => $items,
      '#attributes' => array(
        'class' => array(
          'clearfix',
          'current-filters',
        ),
      ),
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $exposed_filters,
  );
}
