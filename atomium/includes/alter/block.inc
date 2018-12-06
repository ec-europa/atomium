<?php

/**
 * @file
 * block.inc
 */

/**
 * Implements hook_block_view_alter().
 */
function atomium_block_view_alter(&$build, $block) {
  // Strict typing has been disabled for this function until
  // https://www.drupal.org/project/facetapi/issues/2976814
  // and
  // https://www.drupal.org/project/workbench/issues/2976812
  // are not committed.
  //
  // Add a specific atomium key.
  // This will be used in the block preprocess later.
  if (!isset($block->atomium) || !\is_array($block->atomium)) {
    $block->atomium = array();
  }

  $block->atomium += array(
    'total_blocks_in_regions' => 0,
    'block_index_in_region' => 0,
  );
}
