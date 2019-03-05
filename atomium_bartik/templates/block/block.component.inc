<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_block(array &$variables, $hook) {
  // In the header region visually hide block titles.
  if ($variables['block']->region === 'header') {
    $variables['atomium']['attributes']['subject']->append('class', 'element-invisible');
  }
}
