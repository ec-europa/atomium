<?php

/**
 * @file
 * Breadcrumb.preprocess.inc.
 */

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_bootstrap_preprocess_breadcrumb(&$variables) {
  $variables['links']['#type'] = 'ol';
  $variables['links']['#attributes']['class'][] = 'breadcrumb';
}
