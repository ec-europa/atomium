<?php

/**
 * @file
 * username.preprocess.inc
 */

/**
 * Implements hook_preprocess_username().
 */
function atomium_preprocess_username(&$variables) {
  if (isset($variables['uid'])) {
    $variables['theme_hook_suggestions'][] = 'username__uid_' . $variables['uid'];
  }
  if (isset($variables['name'])) {
    $variables['theme_hook_suggestions'][] = 'username__name_' . $variables['name'];
  }

  $variables['link_options'] += array(
    'attributes' => array(),
  );

  if (isset($variables['link_path'])) {
    $variables['name'] = array(
      '#theme' => 'link',
      '#text' => $variables['name'] . $variables['extra'],
      '#path' => $variables['link_path'],
      '#options' => $variables['link_options'],
    );
  }
}
