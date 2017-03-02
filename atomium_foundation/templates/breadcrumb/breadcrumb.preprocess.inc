<?php

/**
 * @file
 * breadcrumb.preprocess.inc
 */

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_foundation_preprocess_breadcrumb(&$variables) {
  $variables['links']['#attributes']['class'][] = 'no-bullet';
  $variables['wrapper_attributes_array'] = array(
    'class' => array(
      'breadcrumbs',
    ),
    'rel' => 'navigation',
    'role' => 'navigation',
    'aria-label' => t('You are here'),
  );
}
