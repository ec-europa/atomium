<?php

/**
 * @file
 * preprocess.inc
 */

/**
 * Implements hook_preprocess().
 */
function atomium_preprocess(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'hook__' . $hook;
  // See how we can extend this properly.
  if ($suggestions = theme_get_suggestions(arg(), $hook)) {
    $variables['theme_hook_suggestions'] = $suggestions;
  }

}
