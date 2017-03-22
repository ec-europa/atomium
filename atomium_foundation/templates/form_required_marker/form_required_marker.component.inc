<?php

/**
 * @file
 * Form_required_marker.preprocess.inc.
 */

/**
 * Implements hook_preprocess_form_required_marker().
 */
function atomium_foundation_preprocess_form_required_marker(&$variables, $hook) {
  $t = get_t();

  $variables[$hook] = $t('Required');
  $variables['attributes_array']['class'][] = array('label', 'alert');
  $variables['attributes_array']['title'] = $t('Required');
}
