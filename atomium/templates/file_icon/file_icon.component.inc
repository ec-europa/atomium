<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_file_icon() {
  return array(
    'file_icon' => array(
      'template' => 'file-icon',
      'variables' => array(
        'file' => NULL,
        'icon_directory' => NULL,
        'alt' => '',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_file_icon(array &$variables, $hook) {
  $file = $variables['file'];

  if (isset($file->filemime)) {
    $mimetype = drupal_html_class($file->filemime);
    // TODO: Add this to the #theme down under.
    $variables['theme_hook_suggestions'][] = $variables['theme_hook_original'] . '__' . $mimetype;
  }

  $variables['atomium']['attributes']['wrapper']->append('class', 'file-icon');

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook('image', $variables['theme_hook_original']),
      '#attributes' => $variables['atomium']['attributes']['wrapper']->toArray(),
      '#alt' => check_plain($variables['alt']),
      '#title' => isset($file->filemime) ? check_plain($file->filemime) : NULL,
      '#path' => file_icon_url($file, $variables['icon_directory']),
    ),
  );
}
