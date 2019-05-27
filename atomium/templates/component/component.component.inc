<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_component(array $existing, $type, $theme, $path) {
  return array(
    'component' => array(
      'template' => 'component',
      'variables' => array(
        'title' => NULL,
        'name' => NULL,
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
function atomium_preprocess_component(array &$variables, $hook) {
  $definitions = array();
  $preview_component = array();

  foreach (atomium_find_templates() as $component_data) {
    if ($component_data['component'] !== $variables['name']) {
      continue;
    }

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

    if (!\is_array($definition['dependencies'])) {
      $definition['dependencies'] = array($definition['dependencies']);
    }

    $errors = array();
    $skip = FALSE;
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
        $skip = TRUE;
        $definition['preview'] = array(
          '#theme' => 'item_list',
          '#items' => $errors[$component],
          '#type' => FALSE,
        );
        $component = $definition;
      }
    }

    if ($skip === TRUE) {
      continue;
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
        $definition['preview'] = $elements;

        _atomium_extend_theme_property(
          $definition['preview'],
          array('preview', $component)
        );
      }
    }
    else {
      $definition['preview']['#theme'] = $component;

      _atomium_extend_theme_property(
        $definition['preview'],
        array('preview')
      );
    }

    // Allow the use of a form.
    $function_name = $theme . '_atomium_definition_form_' . $component;
    if (\function_exists($function_name)) {
      $definition['form'] = drupal_get_form($function_name);
    }

    // Disable the preview if we explicitly set the key disable to TRUE.
    if ($definition['disable'] === TRUE) {
      unset($definition['preview']);
    }

    $preview_component = \array_filter($definition);

    if (!empty($errors)) {
      unset($definitions[$component]['form']);
      $preview = $errors[$component];

      _atomium_extend_theme_property(
        $preview,
        array('preview', $component)
      );

      $preview_component = $preview;
    }
  }

  $variables['component'] = $preview_component;
}