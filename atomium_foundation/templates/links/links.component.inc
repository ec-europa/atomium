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

  $variables['links']['#attributes']['class'][] = 'no-bullet';
  $variables['links']['#attributes']['class'][] = 'menu';
  $variables['links']['#attributes']['class'][] = 'expanded';
  $variables['links']['#attributes']['class'][] = 'simple';
}
