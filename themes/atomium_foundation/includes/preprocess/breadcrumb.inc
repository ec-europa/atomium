<?php

/**
 * @file
 * breadcrumb.inc
 */

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_foundation_preprocess_breadcrumb(&$variables) {
  $variables['attributes_array'] = array(
    'class' => array(
      'breadcrumbs',
    ),
  );
}
