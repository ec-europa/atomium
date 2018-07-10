<?php

/**
 * @file
 * process.inc
 */

/**
 * Implements hook_process().
 */
function atomium_process(array &$variables, $hook) {
  atomium_recursive_foreach($variables, function ($key, &$value, &$parent) use (&$variables) {
    if (!isset($variables['theme_hook_original'])) {
      return;
    }

    if ('#theme' === $key) {
      _atomium_extend_theme_property(
        $parent,
        array($variables['theme_hook_original'])
      );
    }
    if ('#theme_wrappers' === $key) {
      _atomium_extend_theme_wrappers_property(
        $parent,
        array($variables['theme_hook_original'])
      );
    }
  });
}
