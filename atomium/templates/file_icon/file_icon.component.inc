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

  $variables['atomium']['attributes']['wrapper']->append('class', 'file-icon');

  $file_icon = array(
    '#theme' => 'image',
    '#attributes' => $variables['atomium']['attributes']['wrapper']->getValuesAsArray(),
    '#alt' => check_plain($variables['alt']),
    '#title' => isset($file->filemime) ? check_plain($file->filemime) : NULL,
    '#path' => file_icon_url($file, $variables['icon_directory']),
  );

  $mimetype = NULL;
  if (isset($file->filemime)) {
    $mimetype = drupal_html_class($file->filemime);
  }

  _atomium_extend_theme_property(
    $file_icon,
    array($mimetype, $variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $file_icon,
  );
}
