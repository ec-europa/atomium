<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_filter_guidelines() {
  return array(
    'filter_guidelines' => array(
      'template' => 'filter-guidelines',
      'variables' => array('format' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_filter_guidelines(&$variables) {
  $variables['attributes_array']['class'][] = 'filter-guidelines-item';
  $variables['attributes_array']['class'][] = 'filter-guidelines-' . $variables['format']->format;

  $variables['attributes_array']['class'] = array_diff($variables['attributes_array']['class'], array('hook__filter_guidelines'));

  $variables['name'] = check_plain($variables['format']->name);
  $variables['tips'] = theme('filter_tips', array('tips' => _filter_tips($variables['format']->format, FALSE)));
}
