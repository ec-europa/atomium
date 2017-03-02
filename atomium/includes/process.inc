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
        return ($value !== NULL && $value !== FALSE && $value !== '' && !empty($value));
      });
      $new_variable = substr($variable_name, 0, -6);
      $variables[$new_variable] = NULL;
      if (!empty($variable_content) && is_array($variable_content)) {
        if (isset($variable_content['class'])) {
          $variable_content['class'] = array_map('drupal_html_class', (array) $variable_content['class']);
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

}
