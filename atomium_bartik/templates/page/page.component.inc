<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_process_hook().
 */
function atomium_bartik_preprocess_page(array &$variables, $hook) {
  if (isset($variables['page']['content']['#theme_wrappers'])) {
    $variables['page']['content']['#theme_wrappers'] = \array_diff($variables['page']['content']['#theme_wrappers'], array('region'));
  }
  $variables['page']['content']['system_main']['#theme_wrappers'] = \array_diff($variables['page']['content']['system_main']['#theme_wrappers'], array('block'));
}

/**
 * Implements hook_process_hook().
 */
function atomium_bartik_process_page(array &$variables, $hook) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($variables);
  }
  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $variables['hide_site_name'] = theme_get_setting('toggle_name') ? FALSE : TRUE;
  $variables['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
  if ($variables['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $variables['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($variables['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty,
    // so we rebuild it.
    $variables['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (
    !empty($variables['title_suffix']['add_or_remove_shortcut']) &&
    $variables['title']) {
    // Add a wrapper div using the title_prefix and
    // title_suffix render elements.
    $variables['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $variables['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $variables['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }
}
