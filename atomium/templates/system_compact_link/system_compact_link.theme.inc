<?php

/**
 * @file
 * system_compact_link.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__system_compact_link() {
  return array(
    'system_compact_link' => array(
      'variables' => array('link' => array()),
      'template' => 'system-compact-link',
    ),
  );
}
