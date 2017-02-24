<?php

/**
 * @file
 * html_tag.inc
 */

/**
 * Implements hook_process_html_tag().
 */
function atomium_process_html_tag(&$variables) {
  $el = &$variables['element'];

  // Remove type="..." and CDATA prefix/suffix.
  unset($el['#attributes']['type'], $el['#value_prefix'], $el['#value_suffix']);

  // Remove media="all" but leave others unaffected.
  if (isset($el['#attributes']['media']) && $el['#attributes']['media'] === 'all') {
    unset($el['#attributes']['media']);
  }
}
