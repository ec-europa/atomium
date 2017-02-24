<?php

/**
 * @file
 * fieldset.inc
 */

/**
 * Implements hook_preprocess_fieldset().
 */
function atomium_foundation_preprocess_fieldset(&$variables) {
  $variables['attributes_array']['class'] = array_merge(
    $variables['element']['#attributes']['class'],
    array('fieldset')
  );
}
