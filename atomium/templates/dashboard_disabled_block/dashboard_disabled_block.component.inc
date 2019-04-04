<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_dashboard_disabled_block(array $existing, $type, $theme, $path) {
  return array(
    'dashboard_disabled_block' => array(
      'render element' => 'element',
      'template' => 'dashboard-disabled-block',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_dashboard_disabled_block(array &$variables, $hook) {
  $block = $variables['block'];

  $variables['atomium']['attributes']['wrapper']
    ->set('id', 'block-' . $block['module'] . '-' . $block['delta'])
    ->append(
      'class',
      array(
        'disabled-block',
        'block',
        'block-' . $block['module'] . '-' . $block['delta'],
        'module-' . $block['module'],
        'delta-' . $block['delta'],
      )
    );

  $variables['title'] = (!empty($block['title']) && $block['title'] !== '<none>') ?
    check_plain($block['title']) :
    check_plain($block['info']);
}
