<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_comment_wrapper() {
  return array(
    'comment_wrapper' => array(
      'render element' => 'content',
      'template' => 'comment-wrapper',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_comment_wrapper(&$variables) {
  $variables['attributes_array'] += array('class' => array());
  $variables += array('classes_array' => array());

  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
  $variables['attributes_array']['id'] = 'comments-wrapper-' . $variables['node']->nid;
}
