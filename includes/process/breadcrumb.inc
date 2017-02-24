<?php

/**
 * @file
 * breadcrumb.inc
 */

/**
 * Implements hook_process_breadcrumb().
 */
function atomium_process_breadcrumb(&$variables) {
  $variables['links'] = array(
    '#theme' => 'item_list',
    '#items' => $variables['breadcrumb'],
    '#type' => 'ul',
    '#attributes' => $variables['attributes_array'],
  );
}
