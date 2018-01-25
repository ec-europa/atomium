<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_admin_block_content() {
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
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_admin_block_content(&$variables, $hook) {
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
