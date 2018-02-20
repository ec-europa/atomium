<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_filter_tips_more_info() {
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
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_filter_tips_more_info(&$variables, $hook) {
  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook('link', $variables['theme_hook_original']),
      '#text' => t('More information about text formats'),
      '#path' => 'filter/tips',
      // @codingStandardsIgnoreLine: False positive.
      '#options' => array('attributes' => array('target' => '_blank')),
    ),
  );
}
