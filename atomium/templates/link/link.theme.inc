<?php

/**
 * @file
 * link.theme.inc
 */

function atomium_theme__link() {
  return array(
    'link' => array(
      'render element' => 'element',
      'template' => 'link',
      'variables' => array(
        'text' => NULL,
        'path' => NULL,
        'options' => array()
      ),
    ),
  );
}
