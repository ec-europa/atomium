<?php

/**
 * @file
 * Indentation.theme.inc.
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

/**
 * Implements hook_preprocess_indentation().
 */
function atomium_preprocess_indentation(&$variables, $hook) {
  $variables['indentation'] = '&nbsp;';
  $variables['attributes_array']['class'][] = 'indentation';
}
