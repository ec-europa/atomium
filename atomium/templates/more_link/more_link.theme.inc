<?php

/**
 * @file
 * more_link.theme.inc
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
