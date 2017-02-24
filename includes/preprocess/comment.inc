<?php

/**
 * @file
 * comment.inc
 */

/**
 * Implements hook_preprocess_comment().
 */
function atomium_preprocess_comment(&$variables) {
  if (isset($variables['elements']['#comment']->new) && $variables['elements']['#comment']->new) {
    $variables['classes_array'][] = 'new';
  }

  if ($variables['status'] == "comment-unpublished") {
    $variables['classes_array'][] = 'unpublished';
  }

  $variables['classes_array'][] = 'comment-' . $variables['id'];
  $variables['classes_array'][] = $variables['zebra'];

  // Remove inline class from the ul links.
  $variables['content']['links']['#attributes']['class'] = array_values(array_diff($variables['content']['links']['#attributes']['class'], array('inline')));

  $variables['attributes_array']['class'] = $variables['classes_array'];
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
