<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_item_list(array $existing, $type, $theme, $path) {
  return array(
    'item_list' => array(
      'template' => 'item-list',
      'variables' => array(
        'items' => array(),
        'title' => array(),
        'type' => 'ul',
        'attributes' => array(),
        'wrapper' => TRUE,
        'wrapper_attributes' => array(
          'class' => array(
            'item-list',
          ),
        ),
        'atomium' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_item_list() {
  return array(
    'label' => 'Item list',
    'description' => 'Item list description.',
    'preview' => array(
      'items' => array(
        'item1' => array(
          'data' => array(
            '#markup' => 'Item 1',
          ),
        ),
        'item2' => array(
          'data' => array(
            '#markup' => 'Item 2',
          ),
          'style' => 'color: red;',
        ),
        'item3' => array(
          'data' => array(
            '#markup' => 'Item 3',
          ),
          'children' => array(
            'item 3.1',
            'item 3.2',
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
  $variables += array(
    'wrapper' => TRUE,
    'wrapper_attributes' => array(),
  );

  if (empty($variables['items'])) {
    return;
  }

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $num_items = \count($variables['items']);
  $i = 0;

  foreach ($variables['items'] as $key => &$item) {
    ++$i;

    $variables['atomium']['attributes'][$key]
      ->append('class', ($i % 2) ? 'even' : 'odd');

    if ($i === 1) {
      $variables['atomium']['attributes'][$key]->append('class', 'first');
    }

    if ($i === $num_items) {
      $variables['atomium']['attributes'][$key]->append('class', 'last');
    }

    if (\is_string($item)) {
      $item = array(
        'data' => $item,
      );
    }

    $item += array(
      'class' => array(),
      '#attributes' => array(),
    );

    $variables['atomium']['attributes'][$key]
      ->append('class', $item['class'])
      ->merge($item['#attributes']);

    // Remove this so it's not considered as a render array when it gets
    // rendered.
    unset($item['class']);

    if (!isset($item['#markup']) && \in_array($variables['type'], array('ul', 'ol'), TRUE)) {
      $item += array(
        '#theme_wrappers' => _atomium_extend_theme_hook(
          'html_tag',
          array($variables['theme_hook_original'])
        ),
        '#tag' => 'li',
      );
    }

    if (isset($item['data'])) {
      if (\is_string($item['data'])) {
        $item['data'] = array(
          '#markup' => $item['data'],
        );
      }
    }

    if (isset($item['children'])) {
      $children = $item['children'];
      unset($item['children']);
      $item['children'] = array(
        '#theme' => 'item_list',
        '#items' => $children,
        '#type' => $variables['type'],
        '#title' => NULL,
      );
    }

    $item['#attributes'] = $variables['atomium']['attributes'][$key]
      ->merge($item['#attributes'])
      ->toArray();

    // We do this to ensure that component like menu_local_task will have
    // the proper attributes.
    $item['#atomium']['attributes']['wrapper'] =
      $variables['atomium']['attributes'][$key];
  }

  // @Todo: Remove this, it shouldn't be used anymore but it's too early now.
  $variables['atomium']['attributes']['list']
    ->merge($variables['attributes']);
  $variables['atomium']['attributes']['wrapper']
    ->merge($variables['wrapper_attributes']);
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_item_list__pager(array &$variables, $hook) {
  foreach ($variables['items'] as $key => &$item) {
    if ($item['pager_item']['#printed'] === TRUE) {
      unset($variables['items'][$key]);
    }
  }
}
