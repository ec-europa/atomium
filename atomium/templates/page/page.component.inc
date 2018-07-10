<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_page(array &$variables, $hook) {
  $variables['page_manager_control'] = NULL;
  if (isset($variables['node'])) {
    // Tell the template whether the node is panelizer-controlled.
    $variables['page_manager_control'] = isset($variables['node']->panelizer_view_mode) ? $variables['node']->panelizer_view_mode : NULL;
  }

  // page--nodetype.tpl.php.
  if (isset($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }

  // Custom 404.
  $headers = drupal_get_http_header();
  if (isset($headers['status']) && $headers['status'] == '404 Not Found') {
    $variables['theme_hook_suggestions'][] = 'page__404';
  }

  if (isset($variables['page']['content']['system_main'])) {
    if (!empty($variables['page']['content']['system_main']['default_message'])) {
      // Remove the "theres no content default yadi yada" from the frontpage.
      unset($variables['page']['content']['system_main']['default_message']);
    }
    if (!empty($variables['page']['content']['system_main']['#theme_wrappers'])) {
      // Remove the block hook wrapper from the main content block.
      $variables['page']['content']['system_main']['#theme_wrappers'] = array_filter(
        $variables['page']['content']['system_main']['#theme_wrappers'],
        function ($theme_hook) {
          if ('block' === atomium_get_base_hook($theme_hook)) {
            return FALSE;
          }

          return TRUE;
        }
      );
    }
  }

  /*-
  USER ACCOUNT TABS
  Removes the tabs from user login, register & password
  fixes the titles to so no more "user account" all over
   */
  switch (current_path()) {
    case 'user':
      drupal_set_title(t('Log in'));
      break;

    case 'user/register':
      drupal_set_title(t('Create new account'));
      break;

    case 'user/password':
      drupal_set_title(t('Request new password'));
      break;

    default:
      // code...
      break;
  }

  $messages = '';
  if ($variables['show_messages']) {
    $messages = array(
      '#theme' => 'status_messages',
    );

    _atomium_extend_theme_property(
      $messages,
      array($variables['theme_hook_original']));
  }
  $variables['messages'] = $messages;

  $variables['breadcrumb'] = array(
    '#theme' => 'breadcrumb',
    '#breadcrumb' => atomium_drupal_get_breadcrumb(),
  );

  _atomium_extend_theme_property(
    $variables['breadcrumb'],
    array($variables['theme_hook_original']));

  $variables['action_links'] = array(
    '#theme' => 'item_list',
    '#items' => menu_local_actions(),
    '#attributes' => array(
      'class' => array(
        'action_links',
      ),
    ),
  );

  _atomium_extend_theme_property(
    $variables['action_links'],
    array($variables['theme_hook_original']));

  unset($variables['page']['content']['#theme_wrappers']);
}
