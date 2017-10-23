<?php

/**
 * @file
 * process.inc
 */

/**
 * Implements hook_process().
 */
function atomium_process(&$variables, $hook) {
  atomium_recursive_foreach($variables, function ($key, &$value, &$parent) use (&$variables) {
    if (is_string($value) && '#theme' === $key) {
      $value = array($value);
    }

    // #theme_wrappers key handling.
    if (is_array($value) && ('#theme_wrappers' === $key || '#theme' === $key)) {
      // The dashboard module uses multidimensional arrays in the
      // #theme_wrappers values. We need to deal with that as well.
      // This is why we are using this to flatten the array properly.
      if (isset($variables['theme_hook_original'])) {
        $value = array_map(function ($wrapper) use ($variables) {
          return $wrapper . '__' . $variables['theme_hook_original'];
        }, iterator_to_array(new RecursiveIteratorIterator(new RecursiveArrayIterator($value)), FALSE));
      }
    }
  });
}
