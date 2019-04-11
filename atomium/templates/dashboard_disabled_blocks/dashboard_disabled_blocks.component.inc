<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_dashboard_disabled_blocks(array $existing, $type, $theme, $path) {
  return array(
    'dashboard_disabled_blocks' => array(
      'render element' => 'element',
      'template' => 'dashboard-disabled-blocks',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_dashboard_disabled_blocks(array &$variables, $hook) {
  $variables['disabled_blocks'] = array();

  foreach ($variables['blocks'] as $block) {
    $variables['disabled_blocks'][] = array(
      '#theme' => 'dashboard_disabled_block',
      '#block' => $block,
    );
  }

  $variables['help_text'] = t('Drag and drop these blocks to the columns below. Changes are automatically saved. More options are available on the <a href="@dashboard-url">configuration page</a>.', array('@dashboard-url' => url('admin/dashboard/configure')));

  $variables['add_other_blocks'] = array(
    '#theme' => 'link',
    '#text' => t('Add other blocks'),
    '#path' => 'admin/dashboard/configure',
  );

  _atomium_extend_theme_property(
    $variables['add_other_blocks'],
    array($variables['theme_hook_original'])
  );
}
