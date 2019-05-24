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
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function atomium_preprocess_atomium_overview(array &$variables, $hook) {
  $definitions = array();

  foreach (atomium_find_templates() as $component_data) {
    $component = $component_data['component'];
    $definition = _atomium_build_component_preview_box($component_data);

    if ($definition === NULL) {
      continue;
    }

    if (!isset($definition['label'])) {
      continue;
    }

    $definitions[$component] = $definition;
  }

  $variables['definitions'] = $definitions;
}
