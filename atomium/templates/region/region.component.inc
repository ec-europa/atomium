<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_region(&$variables, $hook) {
  $variables['atomium']['attributes']['region']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['region']->remove('class', atomium_get_settings('preprocess.region.classes_to_remove', TRUE));
  $variables['atomium']['attributes']['region']->append('role', 'complementary');

  $variables[$variables['base_hook']] = $variables['content'];
}
