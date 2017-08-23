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
function atomium_preprocess_feed_icon(&$variables, $hook) {
  $text = t('Subscribe to !feed-title', array('!feed-title' => $variables['title']));
  $variables[$hook] = array(
    $hook => array(
      '#theme' => array('link'),
      '#text' => array(
        '#theme' => array('image'),
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
    ),
  );
}
