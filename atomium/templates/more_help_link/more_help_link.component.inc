<?php

/**
 * @file
 * More_help_link.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__more_help_link() {
  return array(
    'more_help_link' => array(
      'template' => 'more-help-link',
      'variables' => array('url' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_more_help_link().
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
