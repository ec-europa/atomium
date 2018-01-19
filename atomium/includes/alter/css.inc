<?php

/**
 * @file
 * css.inc
 */

/**
 * Implements hook_css_alter().
 */
function atomium_css_alter(&$css) {
  // Automatically includes css file from a component if it exists.
  foreach (atomium_find_templates() as $theme_data) {
    foreach ($theme_data as $component => $component_data) {
      $css_file = sprintf('%s/%s.css', $component_data['directory'], $component);
      if (file_exists($css_file)) {
        $css = drupal_add_css($css_file, array(
          'group' => CSS_THEME,
          'every_page' => TRUE,
        ));
      }
    }
  }

  // Exclude specified CSS files from theme.
  $excludes = atomium_get_settings('alter.css_alter.exclude', FALSE);

  if (!empty($excludes)) {
    $excludes = array_merge($excludes, str_replace('.css', '-rtl.css', $excludes));
    $css = array_diff_key($css, drupal_map_assoc($excludes));
  }
}
