<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_pager(&$variables, $hook) {
  $variables[$hook][$hook]['#attributes']['class'][] = 'pagination';

  if (isset($variables[$hook][$hook]['#items'])) {
    if ($variables[$hook][$hook]['#items']['pager_current']['#attributes']) {
      $variables[$hook][$hook]['#items']['pager_current']['#attributes']['class'][] = 'current';
    }
  }
}
