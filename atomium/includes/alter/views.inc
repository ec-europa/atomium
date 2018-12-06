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
  $style_plugin = $view->style_plugin->definition['theme'];

  $extend = array(
    $style_plugin,
    $view->name,
    $display->display_plugin,
  );

  if ($display->id !== $display->display_plugin) {
    $extend[] = $display->id;
  }

  if (isset($view->display_handler->definition['theme'])) {
    $view->display_handler->definition['theme'] = \current(
      _atomium_extend_theme_hook(
        $view->display_handler->definition['theme'],
        $extend
      )
    );
  }

  if (isset($view->style_plugin->definition['theme'])) {
    $view->style_plugin->definition['theme'] = \current(
      _atomium_extend_theme_hook(
        $view->style_plugin->definition['theme'],
        \array_slice($extend, 1)
      )
    );
  }
}
