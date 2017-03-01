<?php

/**
 * @file
 * more_help_link.preprocess.inc
 */

/**
 * Implements hook_preprocess_more_help_link().
 */
function atomium_preprocess_more_help_link(&$variables) {
  $variables['link'] = array(
    '#theme' => 'link',
    '#text' => t('More help'),
    '#path' => $variables['url'],
    '#options' => array('attributes' => array('title' => t('More help'))),
  );
  $variables['attributes_array']['class'][] = 'more-help-link';
}
