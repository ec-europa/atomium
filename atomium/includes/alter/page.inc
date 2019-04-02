<?php

/**
 * @file
 * page.inc
 */

/**
 * Implements hook_page_alter().
 */
function atomium_page_alter(array &$page) {
  $recursive_context = array(
    'blocks info' => array(),
  );

  // Find all the blocks in the page.
  _atomium_recursive_element_children(
    $page,
    function ($element, $element_key, &$recursive_context) {
      $recursive_context += array('block_index_in_region' => array());

      if (isset($element['#block'])) {
        $block = $element['#block'];

        $recursive_context['block_index_in_region'] += array($block->region => 0);

        $recursive_context['blocks info'][$block->bid] = array(
          'block' => $block,
          'block_index_in_region' => $recursive_context['block_index_in_region'][$block->region]++,
        );
      }
    },
    NULL,
    $recursive_context
  );

  // Compute a mapping of regions and number of blocks in them.
  $block_region_count = array();
  foreach ($recursive_context['blocks info'] as $bid => $info) {
    $block_region_count += array($info['block']->region => 0);
    $block_region_count[$info['block']->region]++;
  }

  // Store them in the $recursive_context so it's available inside the callback.
  $recursive_context['blocks in regions count'] = $block_region_count;

  // Recursively loops through all the elements in the page.
  _atomium_recursive_element_children(
    $page,
    function (&$element, $element_key, &$recursive_context) {
      if (!isset($element['#block'])) {
        // Detect the region the element is in.
        $region = '';
        foreach ($recursive_context['parents'] as $parent) {
          if (isset($parent['#region'])) {
            $region = $parent['#region'];

            break;
          }
        }

        if (isset($element['#theme_wrappers'])) {
          $element['#theme_wrappers'] =
            _atomium_extend_with_suggestions(
              $element['#theme_wrappers'],
              array($region)
            );
        }

        return;
      }

      $block = $element['#block'];

      _atomium_update_block_render_array(
        $element,
        $block->region,
        $recursive_context['blocks info'][$block->bid]['block_index_in_region'],
        $recursive_context['blocks in regions count'][$block->region]
      );
    },
    NULL,
    $recursive_context
  );
}
