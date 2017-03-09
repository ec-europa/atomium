<?php

/**
 * @file
 * Breadcrumb.preprocess.inc.
 */

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_bootstrap_preprocess_breadcrumb(&$variables, $hook) {
  $variables[$hook][$hook]['#type'] = 'ol';
  $variables[$hook][$hook]['#attributes']['class'][] = 'breadcrumb';
}
