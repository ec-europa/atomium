<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_file(&$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', array('button', 'secondary'));
}
