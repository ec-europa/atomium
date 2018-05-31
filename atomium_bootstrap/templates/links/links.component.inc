<?php

/**
 * @file
 * Links.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_links(array &$variables, $hook) {
  if (!in_array($variables['theme_hook_original'], array('links__node', 'links__comment'))) {
    return;

  }

  // @todo: fix this.
  $variables['atomium']['attributes']['wrapper']
    ->append('class', array('nav', 'nav-pills', 'nav-justified'));
}
