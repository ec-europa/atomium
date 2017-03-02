<?php

/**
 * @file
 * indentation.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__indentation() {
  return array(
    'indentation' => array(
      'template' => 'indentation',
      'variables' => array(
        'size' => 1,
        'indentation' => '&nbsp;',
      ),
    ),
  );
}
