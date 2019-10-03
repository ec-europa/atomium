<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_image_formatter(array $existing, $type, $theme, $path) {
  return array(
    'image_formatter' => array(
      'template' => 'image-formatter',
      'variables' => array(
        'item' => NULL,
        'path' => NULL,
        'image_style' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_image_formatter() {
  $style = 'thumbnail';

  $build = array(
    'label' => 'Image formatter',
    'description' => 'Image formatter description.',
    'dependencies' => array('image'),
  );

  if (module_exists('image')) {
    $source_uri = file_unmanaged_copy(
      drupal_get_path('theme', 'atomium') . '/assets/images/logo.png',
      'public://'
    );

    image_style_create_derivative(
      image_style_load($style),
      $source_uri,
      image_style_path('large', $source_uri)
    );

    $build += array(
      'preview' => array(
        'item' => array(
          'uri' => file_build_uri('logo.png'),
          'width' => 150,
          'height' => 150,
        ),
        'path' => NULL,
        'image_style' => $style,
      ),
    );
  }

  return $build;
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_image_formatter(array &$variables, $hook) {
  $item = $variables['item'];

  // Do not output an empty 'title' attribute.
  if (isset($item['title']) && drupal_strlen($item['title']) === 0) {
    unset($item['title']);
  }

  if (!empty($variables['image_style'])) {
    $build = array(
      '#theme' => _atomium_extend_theme_hook(
        'image_style',
        array(
          $variables['image_style'],
          $variables['theme_hook_original'],
        )
      ),
      '#style_name' => $variables['image_style'],
      '#path' => $item['uri'],
      '#width' => $item['width'],
      '#height' => $item['height'],
      '#alt' => isset($item['alt']) ? $item['alt'] : NULL,
      '#title' => isset($item['title']) ? $item['title'] : NULL,
      '#attributes' => isset($item['attributes']) ? $item['attributes'] : NULL,
    );
  }
  else {
    $build = array(
      '#theme' => _atomium_extend_theme_hook(
        'image',
        array(
          $variables['theme_hook_original'],
        )
      ),
      '#path' => isset($item['uri']) ? $item['uri'] : NULL,
      '#width' => isset($item['width']) ? $item['width'] : NULL,
      '#height' => isset($item['height']) ? $item['height'] : NULL,
      '#alt' => isset($item['alt']) ? $item['alt'] : NULL,
      '#title' => isset($item['title']) ? $item['title'] : NULL,
      '#attributes' => isset($variables['attributes']) ? $variables['attributes'] : NULL,
    );
  }

  // The link path and link options are both optional, but for the options to be
  // processed, the link path must at least be an empty string.
  if (isset($variables['path']['path'])) {
    $path = $variables['path']['path'];
    $options = isset($variables['path']['options']) ? $variables['path']['options'] : array();
    // When displaying an image inside a link, the html option must be TRUE.
    $options['html'] = TRUE;

    $build = array(
      'link' => array(
        '#theme' => _atomium_extend_theme_hook(
          'link',
          $build['#theme']
        ),
        '#text' => $build,
        '#path' => $path,
        '#options' => $options,
      ),
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $build,
  );
}
