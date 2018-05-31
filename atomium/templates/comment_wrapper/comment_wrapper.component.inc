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
function atomium_preprocess_comment_wrapper(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['wrapper']->append('id', 'comments-wrapper-' . $variables['node']->nid);
}
