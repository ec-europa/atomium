<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_more_link() {
  return array(
    'more_link' => array(
      'template' => 'more-link',
      'variables' => array('url' => NULL, 'title' => NULL),
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
      'title' => 'More link title'
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_more_link(array &$variables, $hook) {
  $more_link = array(
    '#theme' => 'link',
    '#text' => t('More'),
    '#path' => $variables['url'],
    '#options' => array('attributes' => array('title' => $variables['title'])),
  );
  _atomium_extend_theme_property(
    $more_link,
    array($variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] = $more_link,
  );
}
