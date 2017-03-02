<?php

/**
 * @file
 * status_messages.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__status_messages() {
  return array(
    'status_messages' => array(
      'variables' => array('display' => NULL),
      'template' => 'status-messages',
    ),
  );
}
