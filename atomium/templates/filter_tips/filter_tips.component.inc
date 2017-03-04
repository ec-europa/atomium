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
    '#context' => array(
      'parents' => array(
        $hook => $variables,
      ),
    ),
  );

  foreach ($variables['tips'] as $name => $tipList) {
    $composer[$name] = array(
      '#type' => 'container',
      '#context' => array(
        'parents' => array(
          $hook => $variables,
        ),
      ),
    );

    $items = array();
    foreach ($tipList as $key => $tip) {
      $items[$key] = array(
        '#type' => 'html_tag',
        '#tag' => 'li',
        '#attributes' => array(
          'class' => array($name),
          'id' => $tip['id'],
        ),
        '#value' => $tip['tip'],
        '#context' => array(
          'parents' => array(
            $hook => $variables,
          ),
        ),
      );
    }

    $composer[$name]['tips'] = array(
      '#theme' => 'item_list',
      '#items' => $items,
      'type' => 'ul',
      '#context' => array(
        'parents' => array(
          $hook => $variables,
        ),
      ),
    );
  }

  $variables['tips'] = $composer;
}
