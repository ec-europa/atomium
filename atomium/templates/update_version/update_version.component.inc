<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_update_version(array $existing, $type, $theme, $path) {
  return array(
    'update_version' => array(
      'template' => 'update-version',
      'variables' => array(
        'version' => NULL,
        'tag' => NULL,
        'class' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_update_version() {
  return array(
    'label' => 'Update version',
    'description' => 'Update version description.',
    'dependencies' => array(
      'update',
    ),
    'preview' => array(
      'version' => array(
        'version' => '3.1415',
        'release_link' => 'https://drupal.org/project/atomium',
        'download_link' => 'https://drupal.org/project/atomium',
        'date' => \time(),
      ),
      'tag' => 'pie',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_update_version(array &$variables, $hook) {
  $variables['atomium']['attributes']['table']->append(
    'class',
    'version',
    $variables['version']
  );

  $variables['version_details'] = array(
    '#theme' => 'link',
    '#text' => $variables['version']['version'],
    '#path' => $variables['version']['release_link'],
  );

  $variables['version_date'] = format_date(
    $variables['version']['date'],
    'custom',
    'Y-M-d'
  );

  $links = array();
  $links['update-download'] = array(
    'title' => t('Download'),
    'href' => $variables['version']['download_link'],
  );
  $links['update-release-notes'] = array(
    'title' => t('Release notes'),
    'href' => $variables['version']['release_link'],
  );

  $variables['links'] = array(
    '#theme' => _atomium_extend_theme_hook(
      'links',
      array(
        $variables['theme_hook_original'],
      )
    ),
    '#links' => $links,
  );
}
