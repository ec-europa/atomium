<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_region(&$variables, $hook) {
  $classes = array(
    'hook__' . $hook . '__' . $variables['region'],
  );

  $variables['classes_array'] = array_merge($variables['classes_array'], $classes);
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('region')));
  $variables['atomium']['attributes']['region']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['region']->append('role', 'complementary');

  $variables[$hook] = $variables['content'];
}
