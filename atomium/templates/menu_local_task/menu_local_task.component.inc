<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_local_task(array $existing, $type, $theme, $path) {
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
function atomium_preprocess_menu_local_task(array &$variables, $hook) {
  $link = $variables['link'];
  $link_text = $link['title'];
  $active = array();

  if (!empty($variables['active']) && $variables['active'] === TRUE) {
    // Add text to indicate active tab for non-visual users.
    $active = array(
      '#markup' => t('(active tab)'),
      '#theme_wrappers' => _atomium_extend_theme_hook(
        'html_tag',
        $variables['theme_hook_original']
      ),
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array(
          'element-invisible',
        ),
      ),
    );

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
  }

  $variables[$variables['base_hook']] = $link_text;
  if (isset($link['href'])) {
    $variables[$variables['base_hook']] = array(
      $variables['base_hook'] => array(
        '#theme' => _atomium_extend_theme_hook(
          'link',
          $variables['theme_hook_original']
        ),
        // TODO: This render() call needs to be removed when #381 is merged.
        '#text' => $link['title'] . render($active),
        '#path' => $link['href'],
        '#options' => array(
          'attributes' => array('title' => $link['title']),
          'html' => TRUE,
        ),
      ),
    );
  }

  if (!empty($variables['active'])) {
    $variables['atomium']['attributes']['wrapper']->append('class', 'active');
  }
}
