<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
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

  $variables['messages'] = $variables['show_messages'] ? array('#theme' => array('status_messages')) : '';
  $variables['breadcrumb'] = array(
    '#theme' => array('breadcrumb'),
    '#breadcrumb' => atomium_drupal_get_breadcrumb(),
  );
  $variables['action_links'] = array(
    '#theme' => array('item_list'),
    '#items' => menu_local_actions(),
    '#attributes' => array(
      'class' => array(
        'action_links',
      ),
    ),
  );

  unset($variables['page']['content']['#theme_wrappers']);
}
