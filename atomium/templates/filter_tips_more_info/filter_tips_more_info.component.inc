<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_filter_tips_more_info(array $existing, $type, $theme, $path) {
  return array(
    'filter_tips_more_info' => array(
      'template' => 'filter-tips-more-info',
      'variables' => array(
        'link' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_filter_tips_more_info() {
  return array(
    'label' => 'Filter tips more info',
    'description' => 'Filter tips more info description.',
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_filter_tips_more_info(array &$variables, $hook) {
  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#type' => 'atomium_link',
      '#theme_hook_suggestions_parts' => array(
        $variables['theme_hook_original'],
      ),
      '#title' => t('More information about text formats'),
      '#href' => 'filter/tips',
      '#options' => array(
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
  );
}
