<?php

/**
 * @file
 * The primary PHP file for the Drupal Atomium base theme.
 *
 * This file should only contain light helper functions and point to stubs in
 * other files containing more complex functions.
 *
 * The stubs should point to files within the `./includes` folder named after
 * the function itself minus the theme prefix. If the stub contains a group of
 * functions, then please organize them so they are related in some way and name
 * the file appropriately to at least hint at what it contains.
 *
 * All [pre]process functions, theme functions and template files lives inside
 * the `./templates` folder. This is a highly automated and complex system
 * designed to only load the necessary files when a given theme hook is invoked.
 */

// Auto-rebuild the theme registry during theme development.
if (theme_get_setting('atomium_rebuild_registry') && !\defined('MAINTENANCE_MODE')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}

/**
 * Include common functions used through out theme.
 */
include_once drupal_dirname(__FILE__) . '/includes/common.inc';

atomium_include('atomium', 'includes/config.inc');
atomium_include('atomium', 'includes/preprocess.inc');
atomium_include('atomium', 'includes/process.inc');
atomium_include('atomium', 'includes/classes');

/**
 * Implements hook_theme().
 */
function atomium_theme(&$existing, $type, $theme, $path) {
  atomium_include('atomium', 'includes/registry.inc');

  return _atomium_theme($existing, $type, $theme, $path);
}

/**
 * Implements hook_menu_alter().
 */
function atomium_menu_alter(array &$items) {
  $items['atomium-overview'] = array(
    'title' => 'Atomium overview',
    'page callback' => 'theme',
    'page arguments' => array('atomium_overview'),
    'access arguments' => array('administer themes'),
    'type' => MENU_CALLBACK,
  );

  $items['atomium-overview/%'] = array(
    'title' => 'Atomium overview',
    'page callback' => 'atomium_overview_component_single',
    'page arguments' => array(1),
    'access arguments' => array('administer themes'),
  );
}

/**
 * Load a single component.
 *
 * @param string $_component_name
 *   The component name pass as path.
 *
 * @return mixed|null
 *   The component data if exists, otherwise NULL.
 */
function _atomium_overview_component_single_load_component($_component_name) {
  foreach (atomium_find_templates() as $component_data) {
    if ($_component_name === $component_data['component']) {
      return $component_data;
    }
  }

  return NULL;
}

/**
 * Implements hook_atomium_theme_hook().
 *
 * In order to prevent infinite loop during a clear cache or during drupal
 * install, we have to generate the list of existing definitions in the
 * preprocess hook.
 */
function atomium_atomium_theme_atomium_overview_component_single(array $existing, $type, $theme, $path) {
  return array(
    'atomium_overview_component_single' => array(
      'template' => 'atomium-overview-component-single',
      'variables' => array(
        'definitions' => array(),
      ),
    ),
  );
}

/**
 * Page callback.
 *
 * @param string $_component_name
 *   The component name.
 *
 * @throws \Exception
 *
 * @return int|string
 *   return the theme otherwise the page not found.
 */
function atomium_overview_component_single($_component_name) {
  // drupal_static('atomium_overview_component_single');.
  $definitions = array();

  foreach (atomium_find_templates() as $component_data) {
    $component_name = $component_data['component'];
    $definition = _atomium_build_component_preview_box($component_data);

    if ($component_name !== $_component_name) {
      continue;
    }

    if ($definition === NULL) {
      return MENU_NOT_FOUND;
    }

    if (!isset($definition['label'])) {
      return MENU_NOT_FOUND;
    }

    $definitions[$component_name] = $definition;

    break;
  }

  if (empty($definitions)) {
    return MENU_NOT_FOUND;
  }

  $variables['definitions'] = $definitions;

  return theme('atomium_overview_component_single', $variables);
}

/**
 * Generates a preview box for a component.
 *
 * The box contains title, description, preview and other parts.
 *
 * @param array $component_data
 *   The component data.
 *
 * @return array|null
 *   A render element with the component preview, or NULL to show nothing.
 *   Array keys:
 *   - title:
 */
function _atomium_build_component_preview_box(array $component_data) {
  $component_name = $component_data['component'];
  $theme = $component_data['theme'];

  if (empty($component_data['includes'])) {
    return NULL;
  }

  foreach ($component_data['includes'] as $file) {
    include_once $file;
  }

  $function_name = sprintf(
    '%s_atomium_definition_%s',
    $theme,
    $component_name
  );

  if (!\function_exists($function_name)) {
    return NULL;
  }

  $definition = (array) $function_name() + array(
    'disable' => FALSE,
    'preview' => array(),
    'dependencies' => array(),
  );

  if (!\is_array($definition['dependencies'])) {
    $definition['dependencies'] = array($definition['dependencies']);
  }

  $errors = array();
  foreach ($definition['dependencies'] as $dependency) {
    if (!module_exists($dependency)) {
      $message = t(
        'The component <em>@component</em> has been disabled because the module <em>@module</em> is missing.',
        array('@component' => $component_name, '@module' => $dependency)
      );
      $errors[$dependency] = array(
        '#markup' => $message,
      );
      drupal_set_message($message, 'warning', FALSE);
    }
  }

  if ($errors) {
    $definition['preview'] = array(
      '#theme' => 'item_list',
      '#items' => $errors,
      '#type' => FALSE,
    );

    return $definition;
  }

  // Prepend hash to all preview properties.
  foreach ($definition['preview'] as $key => $value) {
    if (!\is_numeric($key)) {
      $definition['preview']["#{$key}"] = $value;
      unset($definition['preview'][$key]);
    }
  }

  // Handle preview differently whereas a component is an element or not.
  $element = element_info($component_name);
  if (!empty($element)) {
    $elements = array();

    foreach ($definition['preview'] as $preview) {
      // Prepend hash to all preview properties.
      foreach ($preview as $key => $value) {
        if (!\is_numeric($key)) {
          $preview["#{$key}"] = $value;
          unset($preview[$key]);
        }
      }
      $elements[] = \array_merge($element, $preview);
    }

    if (!empty($elements)) {
      $definition['preview'] = array(
        '#theme' => 'item_list',
        '#items' => $elements,
        '#type' => FALSE,
      );

      _atomium_extend_theme_property(
        $definition['preview'],
        array('preview', $component_name)
      );
    }
  }
  else {
    $definition['preview']['#theme'] = $component_name;

    _atomium_extend_theme_property(
      $definition['preview'],
      array('preview')
    );
  }

  // Allow the use of a form.
  $function_name = $theme . '_atomium_definition_form_' . $component_name;
  if (\function_exists($function_name)) {
    $definition['form'] = drupal_get_form($function_name);
  }

  // Disable the preview if we explicitly set the key disable to TRUE.
  if ($definition['disable'] === TRUE) {
    unset($definition['preview']);
  }

  return \array_filter($definition);
}

/**
 * Clear any previously set element_info() static cache.
 *
 * If element_info() was invoked before the theme was fully initialized, this
 * can cause the theme's alter hook to not be invoked.
 *
 * @see https://www.drupal.org/node/2351731
 */
drupal_static_reset('element_info');

/**
 * Declare various hook_*_alter() hooks.
 *
 * Hook_*_alter() implementations must live (via include) inside this file so
 * they are properly detected when drupal_alter() is invoked.
 */
atomium_include('atomium', 'includes/alter');
