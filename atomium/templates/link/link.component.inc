<?php

/**
 * @file
 * Link.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__link() {
  return array(
    'link' => array(
      'render element' => 'element',
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
 * Implements hook_preprocess_link().
 */
function atomium_preprocess_link(&$variables, $hook) {
  $variables += array('options' => array('attributes' => array()));
  $variables['options'] += array(
    'html' => FALSE,
    'attributes' => array(),
  );

  $variables['attributes_array'] = $variables['options']['attributes'];
  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'] = array_merge((array) $variables['attributes_array']['class'], array('hook__' . $hook));
  $variables['attributes_array']['href'] = url($variables['path'], $variables['options']);

  $variables['text'] = ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text']));
}
