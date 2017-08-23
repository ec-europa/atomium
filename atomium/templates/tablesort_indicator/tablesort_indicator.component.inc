<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_tablesort_indicator() {
  return array(
    'tablesort_indicator' => array(
      'template' => 'tablesort-indicator',
      'variables' => array('style' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_tablesort_indicator(&$variables, $hook) {
  $variables['theme_hook_suggestions'][] = $hook . '__' . $variables['style'];

  $image = array(
    '#theme' => array('image'),
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

  if ($variables['style'] == "asc") {
    $image['#path'] = 'misc/arrow-asc.png';
    $image['#alt'] = $image['#title'] = t('sort ascending');
  }
  else {
    $image['#path'] = 'misc/arrow-desc.png';
    $image['#alt'] = $image['#title'] = t('sort descending');
  }

  $variables[$hook] = array(
    $hook => $image,
  );
}
