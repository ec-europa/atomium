<?php

/**
 * @file
 * bean.inc
 */

/**
 * Implements hook_preprocess_bean().
 */
function atomium_preprocess_bean(&$variables) {
  // Add a theme hook suggestion to the bean so its combinated with its region.
  if ($variables['elements']['#block']->module == "bean" and $variables['elements']['bean']) {
    $variables['theme_hook_suggestions'][] = 'block__bean_' . $variables['elements']['#block']->region;
  }
}
