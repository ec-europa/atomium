<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_link(&$variables, $hook) {
  if (isset($variables['attributes_array']['id']) && 'edit-cancel' == $variables['attributes_array']['id']) {
    $variables['atomium']['attributes']['element']->append('class', 'button');
  }
}
