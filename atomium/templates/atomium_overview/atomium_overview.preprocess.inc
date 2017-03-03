<?php

/**
 * @file
 * Admin_page.preprocess.inc.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_atomium_overview(&$variables, $hook) {
  $variables['definitions'] = atomium_get_component_definitions();
}

/**
 * Get list of component definitions.
 *
 * @return array
 *   List of definitions.
 */
function atomium_get_component_definitions() {
  $definitions = array();
  foreach (atomium_find_templates() as $theme => $theme_data) {
    foreach ($theme_data as $component => $component_data) {

      $file = sprintf('%s/%s.theme.inc', $component_data['directory'], $component);
      if (file_exists($file)) {
        include_once $file;
      }

      $function_name = $theme . '_atomium_overview__' . $component;
      if (function_exists($function_name)) {
        $definition = call_user_func($function_name);

        // Prepend hash to all preview properties.
        foreach ($definition['preview'] as $key => $value) {
          $definition['preview']["#{$key}"] = $value;
          unset($definition['preview'][$key]);
        }

        // Handle preview differently whereas a component is an element or not.
        $element = element_info($component);
        if (!empty($element)) {
          $definition['preview'] = array_merge($element, $definition['preview']);
        }
        else {
          $definition['preview']['#theme'] = $component;
        }

        $definitions[$component] = $definition;
      }
    }
  }
  return $definitions;
}
