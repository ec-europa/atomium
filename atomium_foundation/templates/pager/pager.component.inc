<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_foundation_preprocess_pager(&$variables, $hook) {
  $variables['pager']['#attributes']['class'][] = 'pagination';

  if (isset($variables['pager']['#items'])) {
    if ($variables['pager']['#items']['pager_current']['#attributes']) {
      $variables['pager']['#items']['pager_current']['#attributes']['class'][] = 'current';
    }
  }
}
