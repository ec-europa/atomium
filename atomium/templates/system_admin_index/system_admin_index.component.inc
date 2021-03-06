<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_system_admin_index(array $existing, $type, $theme, $path) {
  return array(
    'admin_page' => array(
      'template' => 'admin-page',
      'variables' => array('blocks' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_system_admin_index(array &$variables, $hook) {
  $toggle_link = array(
    '#theme' => 'system_compact_link',
  );
  _atomium_extend_theme_property(
    $toggle_link,
    array($variables['theme_hook_original']));
  $variables['toggle_link'] = $toggle_link;

  $container = array('left' => array(), 'right' => array());
  $flip = array('left' => 'right', 'right' => 'left');
  $position = 'right';

  // Iterate over all modules.
  foreach ($variables['menu_items'] as $module => list($description, $items)) {
    // Output links.
    if (\count($items) === 0) {
      continue;
    }

    $block_content = array(
      '#theme' => 'admin_block_content',
      '#content' => $items,
    );
    _atomium_extend_theme_property(
      $block_content,
      array($variables['theme_hook_original']));

    $position = $flip[$position];
    $block = array(
      'title' => $module,
      'content' => $block_content,
      'description' => t(
        '@description',
        array('@description' => $description)
      ),
      'show' => TRUE,
      'position' => $flip[$position],
    );

    $block = array(
      '#theme' => 'admin_block',
      '#block' => $block,
    );

    _atomium_extend_theme_property(
      $block,
      array($variables['theme_hook_original']));

    $container[$position][] = $block;
  }

  $variables['container'] = $container;
}
