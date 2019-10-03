<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_user_list(array &$variables, $hook) {
  $users = $variables['users'];
  $variables[$variables['base_hook']] = '';

  if (!empty($users)) {
    $variables[$variables['base_hook']] = array(
      $variables['base_hook'] => array(
        '#theme' => _atomium_extend_theme_hook('item_list', $variables['theme_hook_original']),
        '#items' => \array_map(static function ($user) use ($variables) {
          return array(
            'data' => array(
              '#theme' => _atomium_extend_theme_hook('username', $variables['theme_hook_original']),
              '#account' => $user,
            ),
          );
        }, $users),
        '#title' => $variables['title'],
      ),
    );
  }
}
