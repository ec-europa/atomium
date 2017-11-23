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

    if (isset($page[$region]['#theme_wrappers'])) {
      $page[$region]['#theme_wrappers'] = array_map(function ($item) use ($region) {
        return sprintf('%s__%s', $item, $region);
      }, $page[$region]['#theme_wrappers']);
    }

    $block_index_in_region = 0;
    $blocks = element_children($page[$region]);
    $total_blocks_in_region = count($blocks);

    // Alter each blocks to provides relevant variables in the block preprocess.
    foreach ($blocks as $block) {
      _atomium_update_block_render_array($page[$region][$block], $region, $block_index_in_region++, $total_blocks_in_region);
    }
  }
}
