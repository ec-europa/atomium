<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_more_help_link() {
  return array(
    'more_help_link' => array(
      'template' => 'more-help-link',
      'variables' => array('url' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_more_help_link(&$variables) {
  $variables['link'] = array(
    '#theme' => 'link',
    '#text' => t('More help'),
    '#path' => $variables['url'],
    '#options' => array('attributes' => array('title' => t('More help'))),
  );
  $variables['attributes_array']['class'][] = 'more-help-link';
}
