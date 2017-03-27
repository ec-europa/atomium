<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_bartik_preprocess_admin_page(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'admin';
}
