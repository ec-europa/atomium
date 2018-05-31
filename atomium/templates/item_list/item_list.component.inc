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
        'wrapper_attributes' => array(
          'class' => array(
            'item-list',
          ),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_item_list(array &$variables, $hook) {
  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  if (!empty($variables['items'])) {
    $num_items = count($variables['items']);
    $i = 0;
    foreach ($variables['items'] as $key => $item) {
      $i++;
      if ($i == 1) {
        $variables['atomium']['attributes'][$key]->append('class', 'first');
      }
      if ($i == $num_items) {
        $variables['atomium']['attributes'][$key]->append('class', 'last');
      }

      if (is_array($item) && isset($item['data'])) {
        $item += array('class' => array());
        $variables['atomium']['attributes'][$key]->append('class', $item['class']);
        $variables['items'][$key] = array(
          '#theme' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
          '#tag' => 'li',
          '#atomium' => array(
            'attributes' => array(
              'element' => $variables['atomium']['attributes'][$key],
            ),
          ),
          '#value' => $item['data'],
        );
      }

      if (is_string($item)) {
        $variables['items'][$key] = array(
          '#theme' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
          '#tag' => 'li',
          '#atomium' => array(
            'attributes' => array(
              'element' => $variables['atomium']['attributes'][$key],
            ),
          ),
          '#value' => $item,
        );
      }

      $variables['items'][$key] += array('#attributes' => array());
    }
  }

  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  $variables['atomium']['attributes']['list']->merge($variables['attributes']);
  $variables['atomium']['attributes']['wrapper']->merge($variables['wrapper_attributes']);
}
