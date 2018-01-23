<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_user_profile_category(&$variables, $hook) {
  if (isset($variables['element']['#attributes'])) {
    $variables['atomium']['attributes']['wrapper'] = $variables['element']['#attributes'];
  }
}
