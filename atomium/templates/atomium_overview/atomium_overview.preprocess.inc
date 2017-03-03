<?php

/**
 * @file
 * Admin_page.preprocess.inc.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_atomium_overview(&$variables, $hook) {
  $variables['definitions'] = atomium_get_component_definitions();
}
