<?php

/**
 * @file
 * Menu_local_tasks.preprocess.inc.
 */

/**
 * Implements hook_preprocess_menu_local_tasks().
 */
function atomium_foundation_preprocess_menu_local_tasks(&$variables) {
  $variables['primary']['#type'] = '';
  $variables['primary']['#attributes']['class'][] = 'menu';
  $variables['primary']['#attributes']['class'][] = 'expanded';
  $variables['primary']['#attributes']['class'][] = 'menu-centered';
  $variables['primary']['#attributes']['class'][] = 'button-group';
  $variables['secondary']['#type'] = '';
  $variables['secondary']['#attributes']['class'][] = 'menu';
  $variables['secondary']['#attributes']['class'][] = 'expanded';
  $variables['secondary']['#attributes']['class'][] = 'menu-centered';
  $variables['secondary']['#attributes']['class'][] = 'button-group';
}
