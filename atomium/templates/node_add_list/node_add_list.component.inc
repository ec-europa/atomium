<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_node_add_list(array $existing, $type, $theme, $path) {
  return array(
    'node_add_list' => array(
      'template' => 'node-add-list',
      'variables' => array(
        'content' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_node_add_list(array &$variables, $hook) {
  $variables['message'] = t('You have not created any content types yet. Go to the <a href="@create-content">content type creation page</a> to add a new content type.', array('@create-content' => url('admin/structure/types/add')));

  if (!empty($variables['content'])) {
    foreach ($variables['content'] as &$item) {
      $suggestions = explode('/', $item['href']);
      array_unshift($suggestions, $variables['theme_hook_original']);

      $item = array(
        'link' => array(
          '#theme' => _atomium_extend_theme_hook(
            'link',
            $suggestions
          ),
          '#text' => $item['title'],
          '#path' => $item['href'],
          '#options' => $item['localized_options'],
        ),
        'description' => filter_xss_admin($item['description']),
      );
    }
  }
}
