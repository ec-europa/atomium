<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_mark(array $existing, $type, $theme, $path) {
  return array(
    'mark' => array(
      'template' => 'mark',
      'variables' => array(
        'title' => NULL,
        'type' => MARK_NEW,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_mark() {
  return array(
    'label' => 'Mark',
    'description' => 'Mark description.',
    'preview' => array(
      'title' => 'New stuff!',
      'type' => MARK_NEW,
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_mark(array &$variables, $hook) {
  $type = $variables['type'];

  if ($GLOBALS['user']->uid) {
    if ($type === MARK_NEW) {
      $variables['title'] = !empty($variables['title']) ? $variables['title'] : t('new');
    }
    elseif ($type === MARK_UPDATED) {
      $variables['title'] = !empty($variables['title']) ? $variables['title'] : t('updated');
    }
  }

  $variables['atomium']['attributes']['wrapper']->append('class', 'marker');

  $variables[$variables['base_hook']] = '';
  if (!empty($variables['title'])) {
    $variables[$variables['base_hook']] = $variables['title'];
  }
}
