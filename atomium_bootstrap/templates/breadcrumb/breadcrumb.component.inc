<?php

/**
 * @file
 * Breadcrumb.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_breadcrumb(array &$variables, $hook) {
  if (isset($variables[$hook][$hook])) {
    $variables[$hook][$hook]['#type'] = 'ol';
    $variables[$hook][$hook]['#attributes']['class'][] = 'breadcrumb';
  }
}
