<?php

/**
 * @file
 * The primary PHP file for the Drupal Atomium base theme.
 *
 * This file should only contain light helper functions and point to stubs in
 * other files containing more complex functions.
 *
 * The stubs should point to files within the `./includes` folder named after
 * the function itself minus the theme prefix. If the stub contains a group of
 * functions, then please organize them so they are related in some way and name
 * the file appropriately to at least hint at what it contains.
 *
 * All [pre]process functions, theme functions and template files lives inside
 * the `./templates` folder. This is a highly automated and complex system
 * designed to only load the necessary files when a given theme hook is invoked.
 */

/**
 * Include common functions used through out theme.
 */
include_once __DIR__ . '/includes/common.inc';
include_once __DIR__ . '/includes/config.inc';
include_once __DIR__ . '/includes/preprocess.inc';

/**
 * Implements hook_theme().
 */
function atomium_theme(array &$existing, $type, $theme, $path) {
  include_once __DIR__ . '/includes/registry.inc';

  return _atomium_theme($existing, $type, $theme, $path);
}

/**
 * Implements hook_menu_alter().
 */
function atomium_menu_alter(array &$items) {
  $items['atomium-overview'] = array(
    'title' => 'Atomium overview',
    'page callback' => 'theme',
    'page arguments' => array('atomium_overview'),
    'access arguments' => array('administer themes'),
    'type' => MENU_CALLBACK,
  );
}

/**
 * Clear any previously set element_info() static cache.
 *
 * If element_info() was invoked before the theme was fully initialized, this
 * can cause the theme's alter hook to not be invoked.
 *
 * @see https://www.drupal.org/node/2351731
 */
drupal_static_reset('element_info');

/**
 * Declare various hook_*_alter() hooks.
 *
 * Hook_*_alter() implementations must live (via include) inside this file so
 * they are properly detected when drupal_alter() is invoked.
 */
atomium_include('atomium', 'includes/alter');
