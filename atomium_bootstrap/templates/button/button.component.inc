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
    if ($variables['element']['#attributes']['id'] === 'edit-submit') {
      $variables['atomium']['attributes']['element']->append('class', 'btn-success');
    }
    if ($variables['element']['#attributes']['id'] === 'edit-delete') {
      $variables['atomium']['attributes']['element']->append('class', 'btn-danger');
    }
  }
}
