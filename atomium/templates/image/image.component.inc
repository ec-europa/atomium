<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_image(array $existing, $type, $theme, $path) {
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
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_image(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('src', file_create_url($variables['path']));

  foreach (array('width', 'height', 'alt', 'title') as $key) {
    if (isset($variables[$key])) {
      $variables['atomium']['attributes']['element']->append($key, $variables[$key]);
    }
  }

  if (isset($variables['style_name'])) {
    $variables['theme_hook_suggestions'][] = 'image__' . $variables['style_name'];
  }

  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  $variables['atomium']['attributes']['element']->merge($variables['attributes']);
}
