<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_region(array &$variables, $hook) {
  if (strpos($variables['elements']['#region'], 'sidebar') !== FALSE) {
    $variables['atomium']['attributes']['wrapper']->append('class', array('large-3', 'columns'));
  }
}
