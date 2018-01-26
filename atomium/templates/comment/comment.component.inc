<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_comment() {
  return array(
    'comment' => array(
      'render element' => 'elements',
      'template' => 'comment',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_comment(&$variables, $hook) {
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

  $variables['atomium']['attributes']['wrapper']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['content']->append('class', 'content');

  $variables['picture'] = NULL;
  if (theme_get_setting('toggle_comment_user_picture')) {
    $variables['picture'] = array(
      '#theme' => _atomium_extend_theme_hook('user_picture', $variables['theme_hook_original']),
      '#account' => $variables['elements']['#comment'],
    );
  }
}
