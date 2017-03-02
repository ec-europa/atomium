<?php

/**
 * @file
 * breadcrumb.preprocess.inc
 */

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_preprocess_breadcrumb(&$variables) {
  $variables['links'] = array(
    '#theme' => 'item_list',
    '#items' => $variables['breadcrumb'],
    '#type' => 'ul',
    '#attributes' => $variables['attributes_array'],
  );
}
