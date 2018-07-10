<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_feed_icon() {
  return array(
    'feed_icon' => array(
      'template' => 'feed-icon',
      'variables' => array(
        'url' => NULL,
        'title' => NULL,
        'link' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_feed_icon(array &$variables, $hook) {
  $text = t(
    'Subscribe to !feed-title',
    array('!feed-title' => $variables['title']));

  $feed_icon = array(
    '#theme' => 'link',
    '#text' => array(
      '#theme' => 'image',
      '#path' => 'misc/feed.png',
      '#width' => 16,
      '#height' => 16,
      '#alt' => $text,
    ),
    '#path' => $variables['url'],
    '#options' => array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('feed-icon'),
        'title' => $text,
      ),
    ),
  );

  _atomium_extend_theme_property(
    $feed_icon,
    array($variables['theme_hook_original']));

  _atomium_extend_theme_property(
    $feed_icon['#text'],
    array($feed_icon['#theme']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $feed_icon,
  );
}
