<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_more_link(array $existing, $type, $theme, $path) {
  return array(
    'more_link' => array(
      'render element' => 'element',
      'template' => 'more-link',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_more_link() {
  return array(
    'label' => 'More link',
    'description' => 'More link description.',
    'preview' => array(
      'url' => '#',
      'title' => 'More link title',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_more_link(array &$variables, $hook) {
  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
      '#text' => t('More'),
      '#path' => $variables['url'],
      '#options' => array('attributes' => array('title' => $variables['title'])),
    ),
  );
}
