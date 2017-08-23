<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_page(&$variables, $hook) {
  // This is important to set this variable to an empty string.
  $variables['action_links']['#type'] = '';
  $variables['action_links']['#wrapper'] = FALSE;
}
