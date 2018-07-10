<?php

/**
 * @file
 * views.inc
 */

/**
 * Implements hook_views_pre_render().
 */
function atomium_views_pre_render(view $view) {
  $display = $view->display[$view->current_display];

  $suggestions_parts = [
    $view->name,
    $display->display_plugin,
  ];

  if ($display->id !== $display->display_plugin) {
    $suggestions_parts[] = $display->id;
  }

  if (isset($view->style_plugin->definition['theme'])) {
    _atomium_extend_value_with_suggestions(
      $view->style_plugin->definition['theme'],
      $suggestions_parts
    );

    array_unshift(
      $suggestions_parts,
      $view->style_plugin->definition['theme']
    );
  }

  if (isset($view->display_handler->definition['theme'])) {
    _atomium_extend_value_with_suggestions(
      $view->display_handler->definition['theme'],
      $suggestions_parts
    );
  }
}
