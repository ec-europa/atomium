<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements theme_HOOK().
 */
function atomium_foundation_preprocess_pager(&$variables, $hook) {
  $variables['pager']['#attributes']['class'][] = 'pagination';

  if (isset($variables['pager']['#items'])) {
    if ($variables['pager']['#items']['pager-current']['#attributes']) {
      $variables['pager']['#items']['pager-current']['#attributes']['class'][] = 'current';
    }
  }
}
