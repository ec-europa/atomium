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

  $variables[$hook]['#markup'] = $t('Required');
  $variables[$hook]['#attributes'] = array(
    'class' => array(
      'label',
      'alert',
    ),
    'title' => $t('Required'),
  );
}
