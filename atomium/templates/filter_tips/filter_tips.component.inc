<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_filter_tips() {
  return array(
    'filter_tips' => array(
      'template' => 'filter-tips',
      'variables' => array(
        'tips' => NULL,
        'long' => FALSE,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_filter_tips(array &$variables, $hook) {
  $items = array();

  foreach ($variables['tips'] as $name => $tip_list) {
    foreach ($tip_list as $key => $tip) {
      $items[$key] = array(
        '#theme' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
        '#tag' => 'li',
        '#atomium' => array(
          'attributes' => array(
            'element' => array(
              'class' => array($name),
              'id' => $tip['id'],
            ),
          ),
        ),
        '#value' => $tip['tip'],
      );
    }
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook('item_list', $variables['theme_hook_original']),
      '#items' => $items,
      '#theme_wrappers' => _atomium_extend_theme_hook('container', $variables['theme_hook_original']),
    ),
  );
}
