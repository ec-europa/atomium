<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_tablesort_indicator(array $existing, $type, $theme, $path) {
  return array(
    'tablesort_indicator' => array(
      'template' => 'tablesort-indicator',
      'variables' => array('style' => NULL),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_tablesort_indicator() {
  return array(
    'label' => 'Tablesort indicator',
    'description' => 'Tablesort indicator description.',
    'preview' => array(
      'style' => 'asc',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_tablesort_indicator(array &$variables, $hook) {
  $variables['theme_hook_suggestions'][] = $hook . '__' . $variables['style'];

  $image = array(
    '#path' => 'misc/arrow-asc.png',
    '#width' => 13,
    '#height' => 13,
    '#alt' => t('sort ascending'),
    '#title' => t('sort ascending'),
    '#attributes' => array(
      'class' => array(
        $variables['style'],
      ),
    ),
  );

  if ($variables['style'] === 'asc') {
    $image['#path'] = 'misc/arrow-asc.png';
    $image['#alt'] = $image['#title'] = t('sort ascending');
    $direction = 'asc';
  }
  else {
    $image['#path'] = 'misc/arrow-desc.png';
    $image['#alt'] = $image['#title'] = t('sort descending');
    $direction = 'desc';
  }

  $image['#theme'] = _atomium_extend_theme_hook('image', array($direction, $variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $image,
  );
}
