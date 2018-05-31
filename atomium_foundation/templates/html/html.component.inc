<?php

/**
 * @file
 * Html.preprocess.inc.
 */

/**
 * Implements hook_preprocess_html().
 */
function atomium_foundation_preprocess_html(array &$variables, $hook) {
  drupal_add_js('https://cdnjs.cloudflare.com/ajax/libs/foundation/6.4.1/js/foundation.min.js', 'external');
  drupal_add_css('https://cdnjs.cloudflare.com/ajax/libs/foundation/6.4.1/css/foundation.min.css', 'external');
}
