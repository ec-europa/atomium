<?php

/**
 * @file
 * Link.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_link(array &$variables, $hook) {
  if (isset($variables['options']['attributes']['id'])) {
    if ('edit-cancel' == $variables['options']['attributes']['id']) {
      $variables['atomium']['attributes']['element']
        ->append('class', array('btn', 'btn-danger'));
    }
  }
}
