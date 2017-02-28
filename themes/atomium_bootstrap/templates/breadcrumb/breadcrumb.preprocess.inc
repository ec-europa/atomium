<?php

/**
 * @file
 * breadcrumb.preprocess.inc
 */

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_bootstrap_preprocess_breadcrumb(&$variables) {
  $variables['attributes_array'] = array(
    'class' => array(
      'breadcrumb',
    ),
  );
}
