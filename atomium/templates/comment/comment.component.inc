<?php

/**
 * @file
 * Comment.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__comment() {
  return array(
    'comment' => array(
      'render element' => 'element',
      'template' => 'comment',
    ),
  );
}

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
