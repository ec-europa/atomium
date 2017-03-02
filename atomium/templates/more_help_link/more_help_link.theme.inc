<?php

/**
 * @file
 * more_help_link.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__more_help_link() {
  return array(
    'more_help_link' => array(
      'template' => 'more-help-link',
      'variables' => array('url' => NULL),
    ),
  );
}
