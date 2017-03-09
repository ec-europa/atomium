<?php

/**
 * @file
 * Links.preprocess.inc.
 */

/**
 * Implements hook_preprocess_links().
 */
function atomium_bootstrap_preprocess_links(&$variables) {
  if (!in_array($variables['theme_hook_original'], array('links__node', 'links__comment'))) {
    return;
  }

  $variables['attributes_array']['class'][] = 'nav';
  $variables['attributes_array']['class'][] = 'nav-pills';
  $variables['attributes_array']['class'][] = 'nav-justified';
}
