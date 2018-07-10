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
function atomium_preprocess_menu_local_task(array &$variables, $hook) {
  $link = $variables['link'];
  $active = NULL;

  if (!empty($variables['active']) && TRUE == $variables['active']) {
    // Add text to indicate active tab for non-visual users.
    $active = array(
      '#markup' => t('(active tab)'),
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'span',
      '#attributes' => array(
        'class' => array(
          'element-invisible',
        ),
      ),
    );

    _atomium_extend_theme_wrappers_property(
      $active,
      array($active['#tag'], $variables['theme_hook_original']));

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
  }

  $menu_local_task = $link['title'];
  if (isset($link['href'])) {
    $menu_local_task = array(
      '#theme' => 'link',
      '#text' => array(
        array('#markup' => $link['title']),
        $active,
      ),
      '#path' => $link['href'],
      '#options' => array(
        'attributes' => array('title' => $link['title']),
        'html' => TRUE,
      ),
    );

    _atomium_extend_theme_property(
      $menu_local_task,
      array($variables['theme_hook_original']));
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $menu_local_task,
  );

  $variables['atomium']['attributes']['wrapper']->append('class', !empty($variables['active']) ? 'active' : '');
}
