<?php

/**
 * @file
 * image.preprocess.inc
 */

/**
 * Implements hook_preprocess_image().
 */
function atomium_preprocess_image(&$variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);

  foreach (array('width', 'height', 'alt', 'title') as $key) {

    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }

  if (isset($variables['style_name'])) {
    $variables['theme_hook_suggestions'][] = 'image__' . $variables['style_name'];
  }

  $variables['attributes_array'] = $attributes;

}
