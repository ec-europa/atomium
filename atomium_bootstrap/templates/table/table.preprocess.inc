<?php

/**
 * @file
 * table.preprocess.inc
 */

/**
 * Implements hook_preprocess_table().
 */
function atomium_bootstrap_preprocess_table(&$variables) {
  $variables['attributes']['class'] = array(
    'table',
    'table-hover',
    'table-striped',
  );
}
