<?php

/**
 * @file
 * link.preprocess.inc
 */

/**
 * Implements hook_preprocess_link().
 */
function atomium_preprocess_link(&$variables) {
  $variables['attributes_array'] = $variables['options']['attributes'];
  $variables['url'] = check_plain(url($variables['path'], $variables['options']));
  $variables['text'] = ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text']));
}
