<?php

/**
 * @file
 * more_link.preprocess.inc
 */

/**
 * Implements hook_preprocess_more_link().
 */
function atomium_preprocess_more_link(&$variables) {
  $variables['link'] = array(
    '#theme' => 'link',
    '#text' => t('More'),
    '#path' => $variables['url'],
    '#options' => array('attributes' => array('title' => $variables['title'])),
  );
}
