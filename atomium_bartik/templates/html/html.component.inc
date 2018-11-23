<?php

/**
 * @file
 * Html.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function atomium_bartik_preprocess_html(array &$variables, $hook) {
  if (!empty($variables['page']['featured'])) {
    $variables['atomium']['attributes']['body']->append('class', 'featured');
  }

  if (!empty($variables['page']['triptych_first'])
    || !empty($variables['page']['triptych_middle'])
    || !empty($variables['page']['triptych_last'])) {
    $variables['atomium']['attributes']['body']->append('class', 'triptych');
  }

  if (!empty($variables['page']['footer_firstcolumn'])
    || !empty($variables['page']['footer_secondcolumn'])
    || !empty($variables['page']['footer_thirdcolumn'])
    || !empty($variables['page']['footer_fourthcolumn'])) {
    $variables['atomium']['attributes']['body']->append('class', 'footer-columns');
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
    $variables['atomium']['attributes']['body']->append('class', 'two-sidebars');
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['atomium']['attributes']['body']->append('class', array('one-sidebar', 'sidebar-first'));
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['atomium']['attributes']['body']->append('class', array('one-sidebar', 'sidebar-second'));
  }
  else {
    $variables['atomium']['attributes']['body']->append('class', 'no-sidebars');
  }
}

/**
 * Implements hook_process_html().
 */
function atomium_bartik_process_html(array &$variables, $hook) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($variables);

  }
}
