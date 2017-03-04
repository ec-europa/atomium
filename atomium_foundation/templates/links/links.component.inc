<?php

/**
 * @file
 * Links.preprocess.inc.
 */

/**
 * Implements hook_preprocess_links().
 */
function atomium_foundation_preprocess_links(&$variables) {
  $variables['attributes_array']['class'][] = 'no-bullet';

  if (!in_array($variables['theme_hook_original'], array('links__node', 'links__comment'))) {
    return;
  }

  $variables['attributes_array']['class'][] = 'menu';
}
