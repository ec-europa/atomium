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

  $variables += array('options' => array('attributes' => array()));
  $variables['options'] += array(
    'html' => FALSE,
    'attributes' => array(),
  );

  if (isset($variables['options']['attributes_array'])) {
    $variables['attributes_array'] = $variables['options']['attributes_array'];
  }
  if (isset($variables['options']['attributes']) && is_array($variables['options']['attributes'])) {
    $variables['attributes_array'] = drupal_array_merge_deep($variables['options']['attributes'], $variables['attributes_array']);
  }

  $path = url($variables['path'], $variables['options']);

  // Append active class.
  if (($path == '/' . $_GET['q'] || ($path == '<front>' && drupal_is_front_page())) &&
    (empty($variables['options']['language']) || $variables['options']['language']->language == $language_url->language)) {
    $variables['options']['attributes']['class'][] = 'active';
    $variables['attributes_array']['class'][] = 'active';
  }

  $variables['attributes_array']['href'] = (strpos($variables['path'], '#') === 0) ? $variables['path'] : $path;
  $variables['attributes_array']['href'] = (strpos($variables['path'], 'javascript:') === 0) ? $variables['path'] : $path;

  if (is_string($variables['text'])) {
    $variables['text'] = array(
      '#markup' => ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])),
    );
  }
}
