<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_more_help_link() {
  return array(
    'more_help_link' => array(
      'template' => 'more-help-link',
      'variables' => array('url' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_more_help_link(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'more-help-link');

  $more_help_link = array(
    $variables['base_hook'] => array(
      '#theme' => 'link',
      '#text' => t('More help'),
      '#path' => $variables['url'],
      '#options' => array('attributes' => array('title' => t('More help'))),
    ),
  );
  _atomium_extend_theme_property(
    $more_help_link,
    array($variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $more_help_link,
  );
}
