<?php

/**
 * @file
 * menu.inc
 */

/**
 * Implements theme_menu_local_tasks().
 */
function atomium_foundation_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<div class="button-group expanded">';
    $variables['primary']['#suffix'] = '</div>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<div class="button-group expanded">';
    $variables['secondary']['#suffix'] = '</div>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 * Implements theme_menu_local_task().
 */
function atomium_foundation_menu_local_task(&$variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }

  // Add section tab styling.
  $link['localized_options']['attributes']['class'] = array(
    'small',
    'button',
    'secondary',
  );

  $output = '';
  $output .= l($link_text, $link['href'], $link['localized_options']);
  return $output;
}
