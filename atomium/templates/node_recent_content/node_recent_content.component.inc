<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_node_recent_content(array $existing, $type, $theme, $path) {
  return array(
    'node_recent_content' => array(
      'template' => 'node-recent-content',
      'variables' => array(
        'node' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_node_recent_content(array &$variables, $hook) {
  $variables['title'] = array(
    'title' => array(
      '#theme' => 'link',
      '#text' => $variables['node']->title,
      '#path' => 'node/' . $variables['node']->nid,
    ),
    'mark' => array(
      '#theme' => 'mark',
      '#type' => node_mark($variables['node']->nid, $variables['node']->changed),
    ),
  );

  $variables['author'] = array(
    '#theme' => 'username',
    '#account' => user_load($variables['node']->uid),
  );

  _atomium_extend_theme_property(
    $variables['title']['title'],
    array($variables['theme_hook_original'])
  );

  _atomium_extend_theme_property(
    $variables['title']['mark'],
    array($variables['theme_hook_original'])
  );

  _atomium_extend_theme_property(
    $variables['author'],
    array($variables['theme_hook_original'])
  );
}
