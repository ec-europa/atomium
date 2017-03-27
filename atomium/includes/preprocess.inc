<?php

/**
 * @file
 * preprocess.inc
 */

/**
 * Implements hook_preprocess().
 */
function atomium_preprocess(&$variables, $hook) {
  $variables = drupal_array_merge_deep($variables, array('attributes_array' => array('class' => array())));

  if (theme_get_setting('atomium_add_hook_classes')) {
    atomium_recursive_foreach($variables, function ($key, &$value, &$parent) use ($variables, $hook) {
      if (is_array($value)) {
        if (strpos($key, 'attributes_array') !== FALSE) {
          $value += array(
            'class' => array(),
          );
          if (is_array($value['class'])) {
            $value['class'][] = 'hook__' . $hook;
            if (isset($variables['theme_hook_original'])) {
              if ($hook != $variables['theme_hook_original']) {
                $value['class'][] = 'hook__' . $variables['theme_hook_original'];
              }
            }
          }
        }
      }
    });
  }
}
