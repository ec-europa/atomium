<?php

/**
 * @file
 * mark.preprocess.inc
 */

/**
 * Implements hook_preprocess_mark().
 */
function atomium_preprocess_mark(&$variables) {
  global $user;
  $type = $variables['type'];

  if ($user->uid) {
    if ($type == MARK_NEW) {
      $variables['title'] = !empty($variables['title']) ? t($variables['title']) : t('new');
    }
    elseif ($type == MARK_UPDATED) {
      $variables['title'] = !empty($variables['title']) ? t($variables['title']) : t('updated');
    }
  }
  $variables['attributes_array']['class'][] = 'marker';
}
