<?php

/**
 * @file
 * Mark.preprocess.inc.
 */

/**
 * Implements hook_preprocess_mark().
 */
function atomium_bootstrap_preprocess_mark(&$variables) {
  $variables['attributes_array']['class'][] = 'badge';
}
