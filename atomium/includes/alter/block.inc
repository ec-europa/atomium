<?php

/**
 * @file
 * block.inc
 */

/**
 * Implements hook_block_view_alter().
 */
function atomium_block_view_alter(&$data, $block) {
  // Add a specific atomium key.
  // This will be used in the block preprocess later.
  if (!isset($block->atomium) || !is_array($block->atomium)) {
    $block->atomium = array();
  }

  $block->atomium += array(
    'total_blocks_in_regions' => 0,
    'block_index_in_region' => 0,
  );
}
