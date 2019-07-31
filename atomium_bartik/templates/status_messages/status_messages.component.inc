<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_status_messages(array &$variables, $hook) {
  foreach ($variables['status_messages']['status_messages'] as &$data) {
    unset($data['#theme_wrappers']);

    if (!empty($data['title'])) {
      $data['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h3',
        '#attributes' => array(
          'class' => 'element-invisible',
        ),
        'title' => $data['title'],
      );
    }
  }
}
