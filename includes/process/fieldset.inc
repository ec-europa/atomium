<?php

/**
 * @file
 * fieldset.inc
 */

/**
 * Implements hook_process_fieldset().
 */
function atomium_process_fieldset(&$variables) {
  $element = &$variables['element'];

  $variables['title'] = $element['#title'];
  $variables['description'] = $element['#description'];
}
