<?php

/**
 * @file
 * block.inc
 */

/**
 * Implements hook_preprocess_block().
 */
function atomium_foundation_preprocess_block(&$variables) {
  $variables['classes_array'] = array('clearfix');
}
