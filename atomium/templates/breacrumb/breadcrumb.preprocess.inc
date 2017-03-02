<?php

/**
 * @file
 * breadcrumb.preprocess.inc
 */

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_preprocess_breadcrumb(&$variables) {
  $variables['attributes_array'] = array(
    'rel' => 'navigation',
    'class' => array(
      'breadcrumb',
    ),
  );
}
