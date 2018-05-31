<?php

/**
 * @file
 * Form_required_marker.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_form_required_marker(array &$variables, $hook) {
  $t = get_t();

  $variables[$hook] = $t('Required');
  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'badge')
    ->setAttribute('title', $variables[$hook]);
}
