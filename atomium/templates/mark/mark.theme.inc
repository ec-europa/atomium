<?php

/**
 * @file
 * mark.theme.inc
 */

function atomium_theme__mark() {
  return array(
    'mark' => array(
      'render element' => 'element',
      'template' => 'mark',
      'variables' => array(
        'title' => NULL,
        'type' => MARK_NEW,
      ),
    ),
  );
}
