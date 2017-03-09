<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_mark() {
  return array(
    'mark' => array(
      'render element' => 'element',
      'template' => 'mark',
      'variables' => array(
        'title' => NULL,
        'type' => MARK_NEW,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_mark(&$variables, $hook) {
  global $user;
  $type = $variables['type'];

  if ($user->uid) {
    if ($type == MARK_NEW) {
      $variables['title'] = !empty($variables['title']) ? $variables['title'] : t('new');
    }
    elseif ($type == MARK_UPDATED) {
      $variables['title'] = !empty($variables['title']) ? $variables['title'] : t('updated');
    }
  }

  $variables['attributes_array']['class'][] = 'marker';

  $variables[$hook] = '';
  if (!empty($variables['title'])) {
    $variables[$hook] = array(
      $hook => array(
        '#markup' => $variables['title'],
      ),
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'span',
      '#attributes' => $variables['attributes_array'],
    );
  }
}
