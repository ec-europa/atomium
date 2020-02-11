<?php

/**
 * @file
 * views.inc
 */

/**
 * Implements hook_views_pre_render().
 */
function atomium_views_pre_render(view $view) {
  $extend = array();
  $display = $view->display[$view->current_display];

  if (true === array_key_exists('theme', $view->style_plugin->definition)) {
    $extend[] = $view->style_plugin->definition['theme'];
    $extend[] = $view->name;
    $extend[] = $display->display_plugin;
  }

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
