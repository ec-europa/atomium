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
      'variables' => array(),
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
  $filter_tips_more_info = array(
    '#theme' => 'link',
    '#text' => t('More information about text formats'),
    '#path' => 'filter/tips',
    '#options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ),
  );

  _atomium_extend_theme_property(
    $filter_tips_more_info,
    array($variables['theme_hook_original']));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $filter_tips_more_info,
  );
}
