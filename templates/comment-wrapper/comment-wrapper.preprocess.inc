<?php

/**
 * @file
 * comment.preprocess.inc
 */

/**
 * Implements hook_preprocess_comment_wrapper().
 */
function atomium_preprocess_comment_wrapper(&$variables) {
  $variables['attributes_array'] += array('class' => array());
  $variables += array('classes_array' => array());

  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
  $variables['attributes_array']['id'] = 'comments-wrapper-' . $variables['node']->nid;
}
