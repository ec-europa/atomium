<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_admin_block_content(array $existing, $type, $theme, $path) {
  return array(
    'admin_block_content' => array(
      'template' => 'admin-block-content',
      'variables' => array(
        'content' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_admin_block_content() {
  return array(
    'label' => 'Admin block content',
    'description' => 'Admin block content description.',
    'preview' => array(
      'content' => array(
        array(
          'title' => 'Item title 1',
          'href' => '#',
          'description' => 'Item description 1',
          'localized_options' => array(),
        ),
        array(
          'title' => 'Item title 2',
          'href' => '#',
          'description' => 'Item description 2',
          'localized_options' => array(),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_admin_block_content(array &$variables, $hook) {
  $variables['compact'] = FALSE;

  if (!empty($variables['content'])) {
    $variables['atomium']['attributes']['wrapper']->append('class', 'admin-list');
    if ($variables['compact'] = system_admin_compact_mode()) {
      $variables['atomium']['attributes']['wrapper']->append('class', 'compact');
    }
  }

  foreach ($variables['content'] as &$item) {
    $description = '';
    $link = array(
      '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
      '#text' => $item['title'],
      '#path' => $item['href'],
      '#options' => $item['localized_options'],
    );
    if (!$variables['compact'] && isset($item['description'])) {
      $description = array(
        '#type' => 'markup',
        '#markup' => filter_xss_admin($item['description']),
      );
    }
    $item = array(
      'link' => $link,
      'description' => $description,
    );
  }
}
