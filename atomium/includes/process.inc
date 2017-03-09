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
  // Do not trim arrays because they might be needed later.
  array_walk($variables, function (&$value) {
    if (is_string($value)) {
      $value = trim($value);
    }
  });

  // Convert all variables '*_attributes_array' into a valid
  // '*_attributes' variable.
  foreach ($variables as $variable_name => $variable_content) {
    if (strpos($variable_name, 'attributes_array') === FALSE || in_array($variable_name, array('rdf_template_variable_attributes_array', 'rdf_metadata_attributes_array'))) {
      continue;
    }

    $new_variable = substr($variable_name, 0, -6);
    $variables[$new_variable] = atomium_drupal_attributes($variable_content, $variable_name);
  }
  /* End of attributes processing */

  // Convert 'classes_array' into 'classes'.
  if (isset($variables['classes_array']) && is_array($variables['classes_array'])) {
    $classes_array = $variables['classes_array'];
    array_walk($classes_array, 'drupal_html_class');
    $variables['classes'] = implode(' ', $classes_array);
  }

  // This needs to be in the process to alter what has been done by the
  // preprocessing functions before.
  if (isset($variables[$hook]) && is_array($variables[$hook])) {
    if (isset($variables[$hook]['#theme'])) {
      $variables[$hook]['#theme'] .= '__' . $variables['theme_hook_original'];
    }
    if (isset($variables[$hook][$hook]['#theme'])) {
      $variables[$hook][$hook]['#theme'] .= '__' . $variables['theme_hook_original'];
    }
  }
  if (isset($variables[$hook]) && is_array($variables[$hook])) {
    if (isset($variables[$hook]['#theme_wrappers'])) {
      $variables[$hook]['#theme_wrappers'] = array_map(function ($wrapper) use ($variables) {
        return $wrapper . '__' . $variables['theme_hook_original'];
      }, $variables[$hook]['#theme_wrappers']);
    }
    if (isset($variables[$hook][$hook]['#theme_wrappers'])) {
      $variables[$hook][$hook]['#theme_wrappers'] = array_map(function ($wrapper) use ($variables) {
        return $wrapper . '__' . $variables['theme_hook_original'];
      }, $variables[$hook][$hook]['#theme_wrappers']);
    }
  }
}
