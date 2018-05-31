<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_image_style() {
  return array(
    'image_style' => array(
      'template' => 'image-style',
      'variables' => array(
        'style_name' => NULL,
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
function atomium_preprocess_image_style(array &$variables, $hook) {
  // Determine the dimensions of the styled image.
  $dimensions = array(
    'width' => $variables['width'],
    'height' => $variables['height'],
  );

  image_style_transform_dimensions($variables['style_name'], $dimensions);

  $variables['width'] = $dimensions['width'];
  $variables['height'] = $dimensions['height'];

  if (isset($variables['style_name'])) {
    $variables['theme_hook_suggestions'][] = $variables['theme_hook_original'] . '__' . $variables['style_name'];
  }

  // Determine the URL for the styled image.
  $variables['path'] = image_style_url($variables['style_name'], $variables['path']);
  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook('image', $variables['theme_hook_original']),
      '#path' => $variables['path'],
      '#width' => $variables['width'],
      '#height' => $variables['width'],
      '#alt' => isset($variables['alt']) ? $variables['alt'] : NULL,
      '#title' => isset($variables['title']) ? $variables['title'] : NULL,
      '#attributes' => isset($variables['attributes']) ? $variables['attributes'] : NULL,
    ),
  );
}
