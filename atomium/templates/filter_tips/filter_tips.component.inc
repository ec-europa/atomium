<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_filter_tips() {
  return array(
    'filter_tips' => array(
      'template' => 'filter-tips',
      'variables' => array('tips' => NULL, 'long' => FALSE),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_filter_tips(&$variables, $hook) {
  $composer = array(
    '#type' => 'container',
  );

  foreach ($variables['tips'] as $name => $tipList) {
    $composer[$name] = array(
      '#type' => 'container',
    );

    $items = array();
    foreach ($tipList as $key => $tip) {
      $items[$key] = array(
        '#theme' => array('html_tag'),
        '#tag' => 'li',
        '#attributes' => array(
          'class' => array($name),
          'id' => $tip['id'],
        ),
        '#value' => $tip['tip'],
      );
    }

    $composer[$name]['tips'] = array(
      '#theme' => array('item_list'),
      '#items' => $items,
      'type' => 'ul',
    );
  }

  $variables['tips'] = $composer;
}
