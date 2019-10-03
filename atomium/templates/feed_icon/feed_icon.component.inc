<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_feed_icon(array $existing, $type, $theme, $path) {
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
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_feed_icon() {
  return array(
    'label' => 'Feed icon',
    'description' => 'Feed icon description.',
    'preview' => array(
      'url' => '#',
      'title' => 'Feed icon title',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_feed_icon(array &$variables, $hook) {
  $text = t(
    'Subscribe to !feed-title',
    array('!feed-title' => $variables['title'])
  );

  $image = array(
    '#theme' => _atomium_extend_theme_hook(
      'image__link',
      $variables['theme_hook_original']
    ),
    '#path' => 'misc/feed.png',
    '#width' => 16,
    '#height' => 16,
    '#alt' => $text,
  );

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook(
        'link',
        $variables['theme_hook_original']
      ),
      // TODO: This render() call needs to be removed when #381 is merged.
      '#text' => render($image),
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
