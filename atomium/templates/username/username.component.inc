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
    $username = array(
      '#type' => 'atomium_link',
      '#theme_hook_suggestions_parts' => array(
        $variables['theme_hook_original'],
        'uid_' . $variables['uid'],
      ),
      '#title' => $variables['name'] . $variables['extra'],
      '#href' => $variables['link_path'],
      '#options' => $variables['link_options'],
    );
  }
  else {
    $username = array(
      '#type' => 'atomium_html_tag',
      '#tag' => 'span',
      '#theme_hook_suggestions_parts' => array(
        $variables['theme_hook_original'],
        'uid_' . $variables['uid'],
      ),
      'value' => array(
        '#markup' => $variables['name'] . $variables['extra'],
      ),
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $username,
  );
}
