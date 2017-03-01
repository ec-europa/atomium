<?php

/**
 * @file
 * indentation.preprocess.inc
 */

/**
 * Implements hook_preprocess_indentation().
 */
function atomium_preprocess_indentation(&$variables, $hook) {
  $variables['indentation'] = '&nbsp;';
  $variables['attributes_array']['class'][] = 'indentation';
}
