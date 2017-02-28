<?php

/**
 * @file
 * html_head.inc
 */

/**
 * Implements hook_html_head_alter().
 */
function atomium_html_head_alter(&$head_elements) {
  // Remove the generator meta.
  unset($head_elements['system_meta_generator']);
  if (isset($head_elements['system_meta_content_type']['#attributes']['content'])) {
    $head_elements['system_meta_content_type']['#attributes'] = array(
      'charset' => str_replace(
        'text/html; charset=',
        '',
        $head_elements['system_meta_content_type']['#attributes']['content']
      ),
    );
  }
}
