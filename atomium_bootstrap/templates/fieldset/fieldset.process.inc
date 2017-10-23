<?php

/**
 * @file
 * fieldset.process.inc
 */

/**
 * Implements hook_process_hook().
 */
function atomium_bootstrap_process_fieldset(&$variables, $hook) {
  if (!empty($variables['title'])) {
    $variables['title'] = filter_xss_admin(render($variables['title']));

  }
  if (!empty($variables['description'])) {
    $variables['description'] = filter_xss_admin(render($variables['description']));
  }
}
