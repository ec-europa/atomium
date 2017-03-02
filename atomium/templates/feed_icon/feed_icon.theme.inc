<?php

/**
 * @file
 * feed_icon.theme.inc
 */

function atomium_theme__feed_icon() {
  return array(
    'feed_icon' => array(
      'template' => 'feed-icon',
      'variables' => array(
        'url' => NULL,
        'title' => NULL,
        'link' => NULL,
      ),
    )
  );
}
