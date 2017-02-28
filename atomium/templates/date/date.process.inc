<?php

/**
 * @file
 * date.process.inc
 */

/**
 * Implements hook_process_date().
 */
function atomium_process_date(&$variables) {
  $element = $variables['element'];
  $variables['date'] = drupal_render_children($element);
}
