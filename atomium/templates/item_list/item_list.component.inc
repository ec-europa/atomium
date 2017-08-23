<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_item_list() {
  return array(
    'item_list' => array(
      'template' => 'item-list',
      'variables' => array(
        'items' => array(),
        'title' => NULL,
        'type' => 'ul',
        'attributes' => array(),
        'wrapper' => TRUE,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_item_list(&$variables, $hook) {
  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  if (!empty($variables['items'])) {
    $num_items = count($variables['items']);
    $i = 0;
    foreach ($variables['items'] as $key => $item) {
      $attributes = array('class' => array());
      $i++;
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }

      if (is_array($item) && isset($item['data'])) {
        $item += array('class' => array());
        $attributes['class'] = drupal_array_merge_deep($attributes['class'], $item['class']);
        $variables['items'][$key] = array(
          '#theme' => array('html_tag'),
          '#tag' => 'li',
          '#attributes' => $attributes,
          '#value' => $item['data'],
        );
      }

      if (is_string($item)) {
        $variables['items'][$key] = array(
          '#theme' => array('html_tag'),
          '#tag' => 'li',
          '#attributes' => $attributes,
          '#value' => $item,
        );
      }

      $variables['items'][$key] += array('#attributes' => array());
      $variables['items'][$key]['#attributes'] = drupal_array_merge_deep($variables['items'][$key]['#attributes'], $attributes);
    }
  }

  $variables['attributes_array'] = $variables['attributes'];
  $variables['wrapper_attributes_array']['class'][] = 'item-list';
}
