<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_block(&$variables) {
  // In the header region visually hide block titles.
  if ($variables['block']->region == 'header') {
    $variables['title_attributes_array']['class'][] = 'element-invisible';
  }
  $variables['classes_array'][] = 'block';

  $variables['content_attributes_array']['class'][] = 'content';
  $variables['attributes_array']['class'] = $variables['classes_array'];
  $variables['attributes_array']['id'] = $variables['block_html_id'];
}
