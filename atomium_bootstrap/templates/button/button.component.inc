<?php

/**
 * @file
 * Button.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_button(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', 'btn');

  if (isset($variables['element']['#attributes']['id'])) {
    if ('edit-submit' == $variables['element']['#attributes']['id']) {
      $variables['atomium']['attributes']['element']->append('class', 'btn-success');
    }
    if ('edit-delete' == $variables['element']['#attributes']['id']) {
      $variables['atomium']['attributes']['element']->append('class', 'btn-danger');
    }
  }
}
