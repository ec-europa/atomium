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
function atomium_atomium_theme_atomium_overview() {
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

  foreach (atomium_discover_templates() as $component_data) {
    $component = $component_data['component'];
    $theme = $component_data['theme'];

    $file = \sprintf('%s/%s.component.inc', $component_data['directory'], $component_data['component']);
    if (\file_exists($file)) {
      include_once $file;
    }

    $function_name = $theme . '_atomium_definition_' . $component;
    if (!\function_exists($function_name)) {
      continue;
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
          array('@component' => $component, '@module' => $dependency)
        );
        $errors[$component][$dependency] = array(
          '#markup' => $message,
        );
        drupal_set_message($message, 'warning', FALSE);
      }
    }

    // Prepend hash to all preview properties.
    foreach ($definition['preview'] as $key => $value) {
      if (!\is_numeric($key)) {
        $definition['preview']["#{$key}"] = $value;
        unset($definition['preview'][$key]);
      }
    }

    // Handle preview differently whereas a component is an element or not.
    $element = element_info($component);
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
          '#theme' => _atomium_extend_theme_hook('item_list', array('preview', $component)),
          '#items' => $elements,
        );
      }
    }
    else {
      $definition['preview']['#theme'] = array($component);
    }

    // Allow the use of a form.
    $function_name = $theme . '_atomium_definition_form_' . $component;
    if (\function_exists($function_name)) {
      $definition['form'] = drupal_get_form($function_name);
    }

    // Disable the preview if we explicitely set the key disable to TRUE.
    if (TRUE == $definition['disable']) {
      unset($definition['preview']);
    }

    $definitions[$component] = \array_filter($definition);
    if (!empty($errors)) {
      unset($definitions[$component]['form']);
      $definitions[$component]['preview'] = array(
        '#theme' => _atomium_extend_theme_hook('item_list', array('preview', $component)),
        '#items' => $errors[$component],
      );
    }
  }

  $variables['definitions'] = $definitions;
}
