<?php

/**
 * @file
 * page.preprocess.inc
 */

/**
 * Implements hook_preprocess_page().
 */
function atomium_preprocess_page(&$variables, $hook) {
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

  // Remove the "theres no content default yadi yada" from the frontpage.
  unset($variables['page']['content']['system_main']['default_message']);

  // Remove the block template wrapper from the main content block.
  $variables['page']['content']['system_main']['#theme_wrappers'] = array_diff($variables['page']['content']['system_main']['#theme_wrappers'], array('block'));

  /*-
  USER ACCOUNT TABS
  Removes the tabs from user login, register & password
  fixes the titles to so no more "user account" all over
   */
  switch (current_path()) {
    case 'user':
      $variables['title'] = t('Login');
      unset($variables['tabs']);
      break;

    case 'user/register':
      $variables['title'] = t('New account');
      unset($variables['tabs']);
      break;

    case 'user/password':
      $variables['title'] = t('I forgot my password');
      unset($variables['tabs']);
      break;

    default:
      // code...
      break;
  }
}
