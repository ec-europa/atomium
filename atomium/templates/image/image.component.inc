<?php

/**
 * @file
 * Image.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__image() {
  return array(
    'image' => array(
      'template' => 'image',
      'variables' => array(
        'path' => NULL,
        'width' => NULL,
        'height' => NULL,
        'alt' => '',
        'title' => NULL,
        'attributes' => array(),
      ),
    ),
  );
}

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
