<?php

/**
 * @file
 * Form_required_marker.preprocess.inc.
 */

/**
 * Implements hook_preprocess_form_required_marker().
 */
function atomium_bootstrap_preprocess_form_required_marker(&$variables) {
  $t = get_t();

  $attributes = array(
    'class' => array(
      'badge',
    ),
    'title' => $t('Required'),
  );

  $variables['attributes_array'] = $attributes;
  $variables['title'] = $t('Required');
}
