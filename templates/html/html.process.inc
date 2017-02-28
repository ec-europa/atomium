<?php

/**
 * @file
 * html.process.process.process.inc
 */

/**
 * Implements hook_process_html().
 */
function atomium_process_html(&$variables, $hook) {
  preg_match_all('/<script(?![^>]+src).*?>([\s\S]*?)<\/script>/s', $variables['scripts'], $matches, PREG_SET_ORDER);
  foreach ($matches as $match) {
    if ($newtag = _atomium_convert_js_inline_to_file($match[1])) {
      $variables['scripts'] = str_replace($match[0], $newtag, $variables['scripts']);
    }
  }
}

/**
 * Custom callback.
 */
function _atomium_convert_js_inline_to_file($data) {
  $directory = "public://js";
  $path = $directory . '/' . sha1($data) . '.js';

  if (!is_dir($directory) || !is_writable($directory)) {
    if (file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    }
  }

  $query_string = REQUEST_TIME;

  $element = array(
    '#tag' => 'script',
    '#value' => '',
    '#attributes' => array(
      'type' => 'text/javascript',
    ),
  );

  if (file_exists($path)) {
    $element['#attributes']['src'] = file_create_url($path) . '?' . $query_string;
    return theme('html_tag', array('element' => $element));
  }

  if ($path = file_unmanaged_save_data($data, $path, FILE_EXISTS_REPLACE)) {
    $element['#attributes']['src'] = file_create_url($path) . '?' . $query_string;
    return theme('html_tag', array('element' => $element));
  }

  return FALSE;
}
