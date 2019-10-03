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
  $variables['toggle_link'] = array(
    '#theme' => _atomium_extend_theme_hook(
      'system_compact_link',
      $variables['theme_hook_original']
    ),
  );

  $container = array('left' => array(), 'right' => array());
  $flip = array('left' => 'right', 'right' => 'left');
  $position = 'left';

  // Iterate over all modules.
  foreach ($variables['menu_items'] as $module => list($description, $items)) {
    // Output links.
    if (\count($items) === 0) {
      continue;
    }

    $position = $flip[$position];

    $container[$flip[$position]][] = array(
      '#theme' => _atomium_extend_theme_hook(
        'admin_block',
        $variables['theme_hook_original']
      ),
      '#block' => array(
        'title' => $module,
        'content' => array(
          '#theme' => _atomium_extend_theme_hook(
            'admin_block_content',
            $variables['theme_hook_original']
          ),
          '#content' => $items,
        ),
        'description' => t('@description', array('@description' => $description)),
        'show' => TRUE,
        'position' => $flip[$position],
      ),
    );
  }

  $variables['container'] = $container;
}
