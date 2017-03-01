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

  /* Attributes processing */
  // Initialize some keys to avoid warnings later.
  $variables += array(
    'classes_array' => array(),
    'attributes_array' => array(),
    'title_attributes_array' => array(),
    'content_attributes_array' => array(),
    'wrapper_attributes_array' => array(),
  );

}
