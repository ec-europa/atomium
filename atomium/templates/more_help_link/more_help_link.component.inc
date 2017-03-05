<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
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
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_more_help_link(&$variables, $hook) {
  $variables['link'] = array(
    '#theme' => 'link__' . $variables['theme_hook_original'],
    '#text' => t('More help'),
    '#path' => $variables['url'],
    '#options' => array('attributes' => array('title' => t('More help'))),
    '#context' => array(
      'parents' => array(
        $hook => $variables,
      ),
    ),
  );
  $variables['attributes_array']['class'][] = 'more-help-link';
}
