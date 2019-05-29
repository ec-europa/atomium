<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_more_help_link(array $existing, $type, $theme, $path) {
  return array(
    'more_help_link' => array(
      'template' => 'more-help-link',
      'variables' => array('url' => NULL),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_more_help_link() {
  return array(
    'label' => 'More help link',
    'description' => 'More help link description.',
    'preview' => array(
      'url' => '#',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_more_help_link(array &$variables, $hook) {
  $variables['atomium']['attributes']['wrapper']->append('class', 'more-help-link');

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#type' => 'atomium_link',
      '#theme_hook_suggestions_parts' => array(
        $variables['theme_hook_original'],
      ),
      '#title' => t('More help'),
      '#href' => $variables['url'],
      '#options' => array(
        'attributes' => array(
          'title' => t('More help'),
        ),
      ),
    ),
  );
}
