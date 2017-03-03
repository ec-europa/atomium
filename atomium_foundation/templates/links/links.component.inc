<?php

/**
 * @file
 * Links.preprocess.inc.
 */

/**
 * Implements hook_preprocess_links().
 */
function atomium_foundation_preprocess_links(&$variables) {
  if (!in_array($variables['theme_hook_original'], array('links__node', 'links__comment'))) {
    return;
  }

  $variables['attributes']['class'] = array('button-group', 'expanded');
  foreach ($variables['links'] as &$link) {
    $link['attributes']['class'][] = 'button';
  }
}
