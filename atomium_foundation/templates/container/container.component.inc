<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_container(array &$variables, $hook) {
  if (isset($variables['element']['#type']) && $type = $variables['element']['#type']) {
    if ($type === 'actions') {
      $variables['atomium']['attributes']['wrapper']->append('class', array('button-group', 'expanded'));
    }
  }
}
