<?php

/**
 * @file
 * Html.preprocess.inc.
 */

/**
 * Implements hook_preprocess_html().
 */
function atomium_bartik_preprocess_html(&$variables, $hook) {
  if (!empty($variables['page']['featured'])) {
    $variables['classes_array'][] = 'featured';
  }

  if (!empty($variables['page']['triptych_first'])
    || !empty($variables['page']['triptych_middle'])
    || !empty($variables['page']['triptych_last'])) {
    $variables['classes_array'][] = 'triptych';
  }

  if (!empty($variables['page']['footer_firstcolumn'])
    || !empty($variables['page']['footer_secondcolumn'])
    || !empty($variables['page']['footer_thirdcolumn'])
    || !empty($variables['page']['footer_fourthcolumn'])) {
    $variables['classes_array'][] = 'footer-columns';
  }

  // Add conditional stylesheets for IE.
  drupal_add_css(
    path_to_theme() . '/assets/css/ie.css',
      array(
        'group' => CSS_THEME,
        'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE),
        'preprocess' => FALSE,
      )
  );
  drupal_add_css(
    path_to_theme() . '/assets/css/ie6.css',
      array(
        'group' => CSS_THEME,
        'browsers' => array('IE' => 'IE 6', '!IE' => FALSE),
        'preprocess' => FALSE,
      )
  );

  // Add information about the number of sidebars.
  if (
    !empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'two-sidebars';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['classes_array'][] = 'one-sidebar';
    $variables['classes_array'][] = 'sidebar-first';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'one-sidebar';
    $variables['classes_array'][] = 'sidebar-second';
  }
  else {
    $variables['classes_array'][] = 'no-sidebars';
  }
}

/**
 * Implements hook_process_html().
 */
function atomium_bartik_process_html(&$variables) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);
  }
}
