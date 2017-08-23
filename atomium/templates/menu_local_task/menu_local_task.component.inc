<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_local_task() {
  return array(
    'menu_local_task' => array(
      'template' => 'menu-local-task',
      'variables' => array(
        'link' => NULL,
        'menu_link' => NULL,
        'active' => FALSE,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_local_task(&$variables, $hook) {
  $link = $variables['link'];
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

  $variables[$hook] = $link_text;
  if (isset($link['href'])) {
    $variables[$hook] = array(
      $hook => array(
        '#theme' => array('link'),
        '#text' => $link_text,
        '#path' => $link['href'],
        '#options' => array(
          'attributes' => array('title' => $link_text),
          'html' => TRUE,
        ),
      ),
    );
  }

  $variables['attributes_array']['class'][] = !empty($variables['active']) ? 'active' : '';
}
