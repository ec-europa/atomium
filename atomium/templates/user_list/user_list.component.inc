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
  $user_list = array();

  if (!empty($users)) {
    $user_list = array(
      '#theme' => 'item_list',
      '#items' => array_map(function ($user) use ($variables) {
        $user = array(
          'data' => array(
            '#theme' => 'username',
            '#account' => $user,
          ),
        );

        _atomium_extend_theme_property(
          $user['data'],
          array('item_list', $variables['theme_hook_original']));

        return $user;
      }, $users),
      '#title' => $variables['title'],
    );

    _atomium_extend_theme_property(
      $user_list,
      array($variables['theme_hook_original']));
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $user_list,
  );
}
