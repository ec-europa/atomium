<?php

/**
 * @file
 * username.inc
 */

/**
 * Implements hook_preprocess_username().
 */
function atomium_preprocess_username(&$variables) {
  if (isset($variables['uid'])) {
    $variables['theme_hook_suggestions'][] = 'username__uid_' . $variables['uid'];
  }
  if (isset($variables['name'])) {
    $variables['theme_hook_suggestions'][] = 'username__name_' . $variables['name'];
  }
}
