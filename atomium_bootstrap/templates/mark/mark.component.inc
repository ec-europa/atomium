<?php

/**
 * @file
 * Mark.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_mark(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'badge');
}
