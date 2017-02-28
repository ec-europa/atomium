<?php

/**
 * @file
 * link.preprocess.inc
 */

/**
 * Implements hook_preprocess_link().
 */
function atomium_preprocess_link(&$variables, $hook) {
  $variables['attributes_array'] = $variables['options']['attributes'];
  $variables['attributes_array']['class'][] = 'hook__' . $hook;
  $variables['attributes_array']['href'] = url($variables['path'], $variables['options']);
  $variables['text'] = ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text']));
}
