<?php

/**
 * @file
 * Indentation.theme.inc.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_indentation() {
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
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_indentation(&$variables, $hook) {
  $variables['indentation'] = '&nbsp;';
  $variables['attributes_array']['class'][] = 'indentation';
}
