<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_page(&$variables, $hook) {
  // This is important to set this variable to an empty string.
  $variables['action_links']['#type'] = 'div';
  $variables['action_links']['#wrapper'] = FALSE;
  $variables['action_links']['#attributes']['class'][] = 'btn-group';
  $variables['action_links']['#attributes']['class'][] = 'btn-group-justified';
}
