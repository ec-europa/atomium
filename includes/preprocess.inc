<?php

/**
 * @file
 * preprocess.inc
 */

/**
 * Implements hook_preprocess().
 */
function atomium_preprocess(&$variables, $hook) {
  // See how we can extend this properly.
  if ($suggestions = theme_get_suggestions(arg(), $hook)) {
    $variables['theme_hook_suggestions'] = $suggestions;
  }
}
