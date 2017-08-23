<?php

/**
 * @file
 * Component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_fieldset(&$variables) {
  $variables['attributes_array']['class'][] = 'fieldset';
}
