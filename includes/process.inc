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

  /* Attributes processing */
  // Initialize some keys to avoid warnings later.
  $variables += array(
    'classes_array' => array(),
    'attributes_array' => array(),
    'title_attributes_array' => array(),
    'content_attributes_array' => array(),
    'wrapper_attributes_array' => array(),
  );

  // Convert all variables '*_attributes_array' into a valid
  // '*_attributes' variable.
  foreach ($variables as $variable_name => $variable_content) {
    if (strpos($variable_name, 'attributes_array') !== FALSE) {
      $variable_content = array_filter($variable_content, function($value) {
        return ($value !== null && $value !== false && $value !== '');
      });
      $new_variable = substr($variable_name, 0, -6);
      $variables[$new_variable] = NULL;
      if (!empty($variable_content) && is_array($variable_content)) {
        if (isset($variable_content['class'])) {
          $variable_content['class'] = array_map('drupal_html_class', (array) $variable_content['class']);
        }
        if (isset($variable_content['placeholder'])) {
          $variable_content['placeholder'] = strip_tags($variable_content['placeholder']);
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
