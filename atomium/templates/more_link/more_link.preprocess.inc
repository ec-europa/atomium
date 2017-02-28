<?php

/**
 * @file
 * more_link.preprocess.inc
 */

/**
 * Implements hook_preprocess_more_link().
 */
function atomium_preprocess_more_link(&$variables) {
  $variables['link'] = l(t('More'), $variables['url'], array('attributes' => array('title' => $variables['title'])));
}
