<?php

/**
 * @file
 * Form_required_marker.preprocess.inc.
 */

/**
 * Implements hook_preprocess_form_required_marker().
 */
function atomium_foundation_preprocess_form_required_marker(&$variables) {
  $t = get_t();

  $attributes = array(
    'class' => array(
      'label',
      'alert',
    ),
    'title' => $t('Required'),
  );

  $variables['attributes_array'] = $attributes;
  $variables['title'] = $t('Required');
}
