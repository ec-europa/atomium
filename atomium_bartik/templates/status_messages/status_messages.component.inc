<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_status_messages(&$variables, $hook) {
  foreach ($variables['status_messages']['status_messages'] as &$data) {
    $data['#theme_wrappers'] = array();
    $data['messages']['#title'] = array(
      'title' => array(
        '#markup' => $data['messages']['#title'],
      ),
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'h3',
      '#attributes' => array(
        'class' => array(
          'element-invisible',
        ),
      ),
    );
  }
}
