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
      '#theme' => _atomium_extend_theme_hook(
        'link',
        array(
          $variables['theme_hook_original'],
        )
      ),
      '#text' => $variables['node']->title,
      '#path' => 'node/' . $variables['node']->nid,
    ),
    'mark' => array(
      '#theme' => _atomium_extend_theme_hook(
        'mark',
        array(
          $variables['theme_hook_original'],
        )
      ),
      '#type' => node_mark(
        $variables['node']->nid,
        $variables['node']->changed
      ),
    ),
  );

  $variables['author'] = array(
    '#theme' => _atomium_extend_theme_hook(
      'username',
      array(
        $variables['theme_hook_original'],
      )
    ),
    '#account' => user_load($variables['node']->uid),
  );
}
