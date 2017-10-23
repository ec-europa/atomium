<?php

/**
 * @file
 * Block.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_block(&$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'clearfix');
}
