<?php

/**
 * @file
 * More_link.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__more_link() {
  return array(
    'more_link' => array(
      'render element' => 'element',
      'template' => 'more-link',
      'variables' => array('url' => NULL, 'title' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_more_link().
 */
function atomium_preprocess_more_link(&$variables) {
  $variables['link'] = array(
    '#theme' => 'link',
    '#text' => t('More'),
    '#path' => $variables['url'],
    '#options' => array('attributes' => array('title' => $variables['title'])),
  );
}
