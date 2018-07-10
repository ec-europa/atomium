<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_username() {
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
  $variables['link_options'] += array(
    'attributes' => array(),
  );

  if (isset($variables['link_path'])) {
    $username = array(
      '#theme' => 'link',
      '#text' => $variables['name'] . $variables['extra'],
      '#path' => $variables['link_path'],
      '#options' => $variables['link_options'],
    );
    _atomium_extend_theme_property(
      $username,
      array(
        'username',
        'uid_' . $variables['uid'],
        $variables['theme_hook_original'],
      )
    );

  }
  else {
    $username = array(
      $variables['base_hook'] => array(
        '#markup' => $variables['name'] . $variables['extra'],
      ),
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'span',
      '#attributes' => $variables['atomium']['attributes']['wrapper']->toArray(),
    );

    _atomium_extend_theme_property(
      $username,
      array(
        $username['#tag'],
        'uid_' . $variables['uid'],
        $variables['theme_hook_original'],
      )
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $username,
  );
}
