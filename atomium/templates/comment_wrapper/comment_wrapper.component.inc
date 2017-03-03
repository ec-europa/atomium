<?php

/**
 * @file
 * Comment_wrapper.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__comment_wrapper() {
  return array(
    'comment_wrapper' => array(
      'render element' => 'element',
      'template' => 'comment_wrapper',
    ),
  );
}

/**
 * Implements hook_preprocess_comment_wrapper().
 */
function atomium_preprocess_comment_wrapper(&$variables) {
  $variables['attributes_array'] += array('class' => array());
  $variables += array('classes_array' => array());

  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
  $variables['attributes_array']['id'] = 'comments-wrapper-' . $variables['node']->nid;
}
