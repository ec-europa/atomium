<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 *
 * In order to prevent infinite loop during a clear cache or during drupal
 * install, we have to generate the list of existing definitions in the
 * preprocess hook.
 */
function atomium_atomium_theme_atomium_overview(array $existing, $type, $theme, $path) {
  return array(
    'atomium_overview' => array(
      'template' => 'atomium-overview',
      'variables' => array(
        'definitions' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_atomium_overview(array &$variables, $hook) {
  $definitions = array();

  foreach (atomium_find_templates() as $component_data) {
    $component = $component_data['component'];
    $theme = $component_data['theme'];

    if (empty($component_data['includes'])) {
      continue;
    }

    foreach ($component_data['includes'] as $file) {
      include_once $file;
    }

    $function_name = sprintf(
      '%s_atomium_definition_%s',
      $theme,
      $component
    );

    if (!\function_exists($function_name)) {
      continue;
    }

    $definition = (array) $function_name() + array(
      'disable' => FALSE,
      'preview' => array(),
      'dependencies' => array(),
    );

    $definitions[$component_data['component']] = array(
      '#theme' => 'component',
      '#title' => $definition['label'],
      '#name' => $component_data['component'],
    );
  }

  $variables['definitions'] = array(
    '#theme' => 'item_list',
    '#items' => $definitions,
  );
}
