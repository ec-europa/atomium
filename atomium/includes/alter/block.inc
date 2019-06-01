<?php

/**
 * @file
 * block.inc
 */

/**
 * Implements hook_block_view_alter().
 */
function atomium_block_view_alter(&$data, $block) {
  if ($data === NULL || array() === $data) {
    return;
  }

  $data += array(
    'content' => '',
  );

  if (empty($data['content'])) {
    return;
  }

  $block_theme_suggestions = array();
  _atomium_add_default_pre_render_variables($data);

  // Specific handling for menus blocks.
  if ($block->module === 'system' || $block->module === 'menu') {
    switch ($block->module) {
      case 'system':
        $menus = menu_list_system_menus();

        break;

      case 'menu':
        $menus = menu_get_menus(FALSE);

        break;

      default:
        $menus = array();
    }

    // Update the block content.
    if (isset($menus[$block->delta])) {
      $context = array(
        'block' => $block,
        'suggestions parts' => array(),
      );

      $alter_menu_tree = function (&$element, $key, &$recursive_context) {
        _atomium_add_default_pre_render_callback($element);
        _atomium_add_default_pre_render_variables($element);

        $element['#depth'] = $recursive_context['level'];
        $level = 'level' . $recursive_context['level'];

        $suggestions = array(
          'module' => $recursive_context['block']->module,
          'delta' => $recursive_context['block']->delta,
          'region' => $recursive_context['block']->region,
          'level' => $level,
        );

        $element['#atomium']['suggestions']['theme_wrappers'] = array_merge(
          $element['#atomium']['suggestions']['theme'],
          $element['#atomium']['suggestions']['theme_wrappers'],
          $suggestions,
          $recursive_context['suggestions parts']
        );

        $element['#atomium']['suggestions']['theme'] = array_merge(
          $element['#atomium']['suggestions']['theme'],
          $recursive_context['suggestions parts']
        );
      };

      // Alteration of the original menu build array.
      atomium_recursive_menu_tree(
        $data['content'],
        $alter_menu_tree,
        NULL,
        $context
      );

      $content = $data['content'];

      // Add the contextual links if any.
      if (isset($data['content']['#contextual_links'])) {
        $content['#contextual_links'] = $data['content']['#contextual_links'];
      }

      $data['content'] = $content;

      // Delete this to avoid duplicates later.
      $block_theme_suggestions = (array) $data['content']['#atomium']['suggestions']['theme'];
    }
  }

  if (!is_array($data['content'])) {
    $data['content'] = array(
      '#markup' => $data['content'],
    );
  }

  _atomium_add_default_pre_render_variables($data['content']);

  // We use array_merge() to not override existing data - ex: the user will be
  // able to add custom suggestions.
  $data['content']['#atomium']['suggestions']['theme'] = array_merge(
    array(
      $block->module,
      $block->delta,
      $block->region,
    ),
    $block_theme_suggestions
  );
  $data['content']['#atomium']['suggestions']['theme_wrappers'] = array_merge(
    array(
      $block->module,
      $block->delta,
      $block->region,
    ),
    $block_theme_suggestions
  );
}
