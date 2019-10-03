<?php

/**
 * @file
 * css.inc
 */

/**
 * Implements hook_css_alter().
 */
function atomium_css_alter(array &$css) {
  // Automatically includes css file from a component if it exists.
  foreach (atomium_discover_templates() as $component_data) {
    $css_file = \sprintf(
      '%s/%s.css',
      $component_data['directory'],
      $component_data['component']
    );

    if (!\file_exists($css_file)) {
      continue;
    }

    $css = drupal_add_css($css_file, array(
      'group' => CSS_THEME,
      'every_page' => TRUE,
    ));
  }

  // Exclude specified CSS files from theme.
  $excludes = atomium_get_settings(
    'alter.css_alter.exclude',
    FALSE
  );

  if (!empty($excludes)) {
    $excludes = \array_merge(
      $excludes,
      \str_replace('.css', '-rtl.css', $excludes)
    );
    $css = \array_diff_key($css, drupal_map_assoc($excludes));
  }
}
