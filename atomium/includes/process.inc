<?php

/**
 * @file
 * process.inc
 */

/**
 * Implements hook_process().
 */
function atomium_process(&$variables, $hook) {
  atomium_recursive_foreach($variables, function ($key, &$value, &$parent) use (&$variables, $hook) {
    if (is_string($value) && '#theme' === $key) {
      $value = array($value);
    }

    // #theme_wrappers key handling.
    if (is_array($value) && ('#theme_wrappers' === $key || '#theme' === $key)) {
      // The dashboard modules use multidimensional arrays in the
      // #theme_wrappers values. We need to deal with that as well.
      // This is why we are using this to flatten the array properly.
      if (isset($variables['theme_hook_original'])) {
        $value_iterator = new RecursiveIteratorIterator(new RecursiveArrayIterator($value));
        $value = array_map(function ($wrapper) use ($variables) {
          return $wrapper . '__' . $variables['theme_hook_original'];
        }, iterator_to_array($value_iterator, FALSE));
      }
    }

    // Convert 'classes_array' into 'classes'.
    if (is_array($value) && 'classes_array' === $key) {
      array_walk($value, 'drupal_html_class');
      $parent['classes'] = implode(' ', $value);
    }

    // Attributes (*_attributes_array) handling & converting.
    if (strpos($key, 'attributes_array') !== FALSE) {
      $parent[drupal_substr($key, 0, -6)] = atomium_drupal_attributes($value, $key, $hook);
    }
  });
}
