<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_link() {
  return array(
    'link' => array(
      'template' => 'link',
      'variables' => array(
        'text' => NULL,
        'path' => NULL,
        'options' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_link(&$variables, $hook) {
  global $language_url;

  $variables += array('options' => array('html' => FALSE));
  $variables['options'] += array(
    'html' => FALSE,
  );

  if (isset($variables['options']['attributes'])) {
    $variables['atomium']['attributes']['element']->merge($variables['options']['attributes']);
  }

  $path = url($variables['path'], $variables['options']);

  // Append active class.
  if (($path == '/' . $_GET['q'] || ($path == '<front>' && drupal_is_front_page())) &&
    (empty($variables['options']['language']) || $variables['options']['language']->language == $language_url->language)) {
    $variables['atomium']['attributes']['element']->append('class', 'active');
  }

  // @todo: Fix this.
  $href = (strpos($variables['path'], '#') === 0) ? $variables['path'] : $path;
  $href = (strpos($variables['path'], 'javascript:') === 0) ? $variables['path'] : $path;
  $variables['atomium']['attributes']['element']->append('href', $href);

  if (is_string($variables['text'])) {
    $variables['text'] = array(
      '#markup' => ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])),
    );
  }

  // @todo: the specific title attribute should be 'strip_tagged()'.
}
