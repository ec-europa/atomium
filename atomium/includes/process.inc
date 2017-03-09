<?php

/**
 * @file
 * process.inc
 */

/**
 * Implements hook_process().
 */
function atomium_process(&$variables, $hook) {
  // Trim each variables that goes into the templates.
  // This needs to be done before the attributes processing because
  // drupal_attributes() adds en extra space on purpose.
  array_walk($variables, function (&$value) {
    if (is_string($value)) {
      $value = trim($value);
    }
  });

  // Convert all variables '*_attributes_array' into a valid
  // '*_attributes' variable.
  foreach ($variables as $variable_name => $variable_content) {
    if (strpos($variable_name, 'attributes_array') !== FALSE && !in_array($variable_name, array('rdf_template_variable_attributes_array', 'rdf_metadata_attributes_array'))) {
      $variable_content = array_filter($variable_content, function ($value) {
        if (!is_array($value)) {
          return (strlen($value) != 0);
        }
        return $value;
      });
      $new_variable = substr($variable_name, 0, -6);
      $variables[$new_variable] = NULL;
      if (!empty($variable_content) && is_array($variable_content)) {
        if (isset($variable_content['class'])) {
          // If this line is enabled, it will cause problem with the filter.js
          // - are converted to _ and JS is not able to find the right
          // object having the appropriate class.
          /*
           * $variable_content['class'] =
           * array_map('drupal_html_class', (array) $variable_content['class']);
           */
          $variable_content['class'] = array_unique($variable_content['class']);
        }
        if (isset($variable_content['placeholder'])) {
          $variable_content['placeholder'] = array_map('strip_tags', (array) $variable_content['placeholder']);
        }
        $variables[$new_variable] = atomium_drupal_attributes($variable_content);
      }
    }
  }
  /* End of attributes processing */

  // Convert 'classes_array' into 'classes'.
  if (isset($variables['classes_array']) && is_array($variables['classes_array'])) {
    $classes_array = $variables['classes_array'];
    array_walk($classes_array, 'drupal_html_class');
    $variables['classes'] = implode(' ', $classes_array);
  }

  /* Theme hooks suggestions handling. */
  $arguments = arg();
  $contexts = array();

  if (isset($variables['element']['#parents'])) {
    $arguments = array_merge($arguments, array_filter($variables['element']['#parents']));
  }

  if (isset($variables['theme_hook_original']) && ($hook != $variables['theme_hook_original'])) {
    $arguments[] = $variables['theme_hook_original'];
  }
  if (isset($variables['context'])) {
    $contexts = $variables['context'];
  }
  elseif (isset($variables['element']['#context'])) {
    $contexts = $variables['element']['#context'];
  }

  foreach ($contexts as $name => $context) {
    if ('parents' == $name) {
      foreach (array_reverse($contexts['parents']) as $parent_context) {
        if (isset($parent_context['theme_hook_original']) && ($hook != $parent_context['theme_hook_original'])) {
          $arguments[] = $parent_context['theme_hook_original'];
        }
      }
      unset($variables['context']['parents']);
      continue;
    }
    if (isset($context['theme_hook_original'])) {
      $arguments[] = $context['theme_hook_original'];
    }
  }

  $arguments = arg();
  // See how we can extend this properly.
  if ($suggestions = theme_get_suggestions($arguments, $hook)) {
    $variables['theme_hook_suggestions'] = array_merge($variables['theme_hook_suggestions'], $suggestions);
  }

  $variables['theme_hook_suggestions'] = array_unique($variables['theme_hook_suggestions']);
  /* End of theme hooks suggestions handling. */
}
