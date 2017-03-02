<?php

/**
 * @file
 * username.theme.inc
 */

function atomium_theme__username() {
  return array(
    'username' => array(
      'render element' => 'element',
      'template' => 'username',
      'variables' => array('account' => NULL),
    ),
  );
}
