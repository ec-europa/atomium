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

    if (isset($page[$region]['#theme_wrappers'])) {
      $page[$region]['#theme_wrappers'] = array_map(function ($item) use ($region) {
        return sprintf('%s__%s', $item, $region);
      }, $page[$region]['#theme_wrappers']);
    }

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

      $adder = str_replace(
        '-',
        '_',
        sprintf(
          '%s__%s__%s',
          $region,
          $page[$region][$block]['#block']->module,
          $page[$region][$block]['#block']->delta
        )
      );

      $page[$region][$block]['#theme_wrappers'] = array_map(function ($item) use ($adder) {
        return sprintf('%s__%s', $item, $adder);
      }, $page[$region][$block]['#theme_wrappers']);

    }
  }
}
