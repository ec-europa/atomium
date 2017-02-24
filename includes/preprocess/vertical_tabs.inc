<?php

/**
 * @file
 * vertical_tabs.inc
 */

/**
 * Implements hook_preprocess_vertical_tabs().
 */
function atomium_preprocess_vertical_tabs(&$variables) {
  drupal_add_library('system', 'drupal.vertical-tabs');
}
