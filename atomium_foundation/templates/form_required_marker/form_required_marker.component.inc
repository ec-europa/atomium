<?php

/**
 * @file
 * Form_required_marker.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_form_required_marker(&$variables, $hook) {
  $t = get_t();

  $variables[$hook] = $t('Required');
  $variables['atomium']['attributes']['wrapper']
    ->append('class', array('label', 'alert'))
    ->setAttribute('title', $variables[$hook]);
}
