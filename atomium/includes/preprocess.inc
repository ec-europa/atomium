<?php

/**
 * @file
 * preprocess.inc
 */

/**
 * Implements hook_preprocess().
 */
function atomium_preprocess(&$variables, $hook) {
  $variables += array(
    'attributes_array' => array(),
  );

  $variables['attributes_array'] += array(
    'class' => array(),
  );
}
