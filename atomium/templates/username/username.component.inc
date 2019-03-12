<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_username(array $existing, $type, $theme, $path) {
  return array(
    'username' => array(
      'template' => 'username',
      'variables' => array('account' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_username(array &$variables, $hook) {
  if (isset($variables['uid'])) {
    $variables['theme_hook_suggestions'][] = 'username__uid_' . $variables['uid'];
  }
  if (isset($variables['name'])) {
    $variables['theme_hook_suggestions'][] = 'username__name_' . drupal_html_class($variables['name']);
  }

  $variables['link_options'] += array(
    'attributes' => array(),
  );

  if (isset($variables['link_path'])) {
    $variables[$variables['base_hook']] = array(
      $variables['base_hook'] => array(
        '#theme' => _atomium_extend_theme_hook('link', array('username', 'uid_' . $variables['uid'])),
        '#text' => $variables['name'] . $variables['extra'],
        '#path' => $variables['link_path'],
        '#options' => $variables['link_options'],
      ),
    );
  }
  else {
    $variables[$variables['base_hook']] = array(
      $variables['base_hook'] => array(
        '#markup' => $variables['name'] . $variables['extra'],
      ),
      '#theme_wrappers' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
      '#tag' => 'span',
      '#attributes' => $variables['atomium']['attributes']['wrapper']->toArray(),
    );
  }
}
