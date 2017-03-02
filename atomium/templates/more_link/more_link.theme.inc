<?php

/**
 * @file
 * more_link.theme.inc
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
