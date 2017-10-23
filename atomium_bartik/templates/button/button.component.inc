<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_button(&$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', 'form-' . $variables['element']['#button_type']);
}
