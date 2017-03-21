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
  atomium_recursive_foreach($variables, function ($key, &$value) use (&$variables, $hook) {
    if (is_string($value)) {
      $value = trim($value);
    }
  });

  atomium_recursive_foreach($variables, function ($key, &$value, &$parent) use (&$variables, $hook) {
    if (is_string($value) && '#theme' === $key) {
      $value = array($value);
    }

    // #theme_wrappers key handling.
    if (is_array($value) && ('#theme_wrappers' === $key || '#theme' === $key)) {
      // The dashboard modules use multidimensionnal arrays in the
      // #theme_wrappers values. We need to deal with that as well.
      // This is why we are using this to flatten the array properly.
      $value_iterator = new RecursiveIteratorIterator(new RecursiveArrayIterator($value));
      $values = array();
      foreach ($value_iterator as $value_item) {
        $values[] = $value_item;
      }
      $value = array_map(function ($wrapper) use ($variables) {
        return $wrapper . '__' . $variables['theme_hook_original'];
      }, $values);
    }

    // Convert 'classes_array' into 'classes'.
    if (is_array($value) && 'classes_array' === $key) {
      array_walk($value, 'drupal_html_class');
      $value['classes'] = implode(' ', $value);
    }

    // Attributes (*_attributes_array) handling & converting.
    if (strpos($key, 'attributes_array') !== FALSE) {
      $variables[substr($key, 0, -6)] = atomium_drupal_attributes($value, $key, $hook);
    }
  });
}
