<?php

/**
 * @file
 * image.theme.inc
 */

function atomium_theme__image() {
  return array(
    'image' => array(
      'template' => 'image',
      'variables' => array(
        'path' => NULL,
        'width' => NULL,
        'height' => NULL,
        'alt' => '',
        'title' => NULL,
        'attributes' => array()
      ),
    ),
  );
}
