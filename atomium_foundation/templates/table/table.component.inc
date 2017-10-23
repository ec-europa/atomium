<?php

/**
 * @file
 * Table.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_table(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', array('hover', 'unstriped'));
}
