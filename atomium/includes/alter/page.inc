<?php

/**
 * @file
 * page.inc
 */

/**
 * Implements hook_page_alter().
 */
function atomium_page_alter(&$page) {
  foreach (system_region_list($GLOBALS['theme'], REGIONS_VISIBLE) as $region => $name) {
    if (empty($page[$region])) {
      continue;
    }
    $count = 0;
    $blocks = element_children($page[$region]);
    $block_count = count($blocks);
    foreach ($blocks as $block) {
      if ($count == 0) {
        $page[$region][$block]['#block']->classes[] = 'first';
      }

      if (isset($page[$region][$block]['#block']) && is_object($page[$region][$block]['#block'])) {
        $page[$region][$block]['#block']->order = $count++;
      }

      if ($count == $block_count) {
        $page[$region][$block]['#block']->classes[] = 'last';
      }
    }
  }
}
