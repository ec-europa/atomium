<?php

/**
 * @file
 * username.process.inc
 */

/**
 * Implements hook_process_username().
 */
function atomium_process_username(&$variables) {
  if (isset($variables['link_path'])) {
    $variables['name'] = l($variables['name'] . $variables['extra'], $variables['link_path'], $variables['link_options']);
  }
}
