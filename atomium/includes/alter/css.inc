<?php

/**
 * @file
 * css.inc
 */

/**
 * Implements hook_css_alter().
 */
function atomium_css_alter(&$css) {
  $theme_key = $GLOBALS['theme_key'];

  // Exclude specified CSS files from theme.
  $excludes = atomium_get_theme_info($theme_key, 'exclude][css', FALSE);

  if (!empty($excludes)) {
    $excludes = array_merge($excludes, str_replace('.css', '-rtl.css', $excludes));
    $css = array_diff_key($css, drupal_map_assoc($excludes));
  }
}
