<?php

/**
 * @file
 * page.inc
 */

/**
 * Implements hook_page_alter().
 */
function atomium_page_alter(array &$page) {
  _atomium_add_default_pre_render_variables($page);

  atomium_recursive_element_children(
    $page,
    function (&$element, $element_key, &$recursive_context) {
      // Detect the region the element is in.
      $region = '';
      foreach ($recursive_context['parents'] as $parent) {
        if (isset($parent['#region'])) {
          $region = $parent['#region'];

          break;
        }
      }

      _atomium_add_default_pre_render_variables($element);

      // Todo: investigate why this condition.
      if (!isset($element['#markup'])) {
        _atomium_add_default_pre_render_callback($element);
      }

      $suggestions = array(
        'region' => $region,
      );

      // Do not add twice the region to the blocks.
      if (!isset($element['#block'])) {
        $element['#atomium']['suggestions']['theme_wrappers'] = array_merge(
          $suggestions,
          $element['#atomium']['suggestions']['theme_wrappers']
        );
      }

      $element['#atomium']['suggestions']['theme'] = array_merge(
        $suggestions,
        $element['#atomium']['suggestions']['theme']
      );
    }
  );
}
