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
        '#theme' => 'html_tag',
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

  array_walk($items, function (&$item) use ($variables) {
    _atomium_extend_theme_property(
      $item,
      array($item['#tag'], $variables['theme_hook_original']));
  });

  $filter_tips = array(
    '#theme' => 'item_list',
    '#theme_wrappers' => array('container'),
    '#items' => $items,
  );

  _atomium_extend_theme_property(
    $filter_tips,
    array($variables['theme_hook_original']));

  _atomium_extend_theme_wrappers_property(
    $filter_tips,
    array($variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $filter_tips,
  );
}
