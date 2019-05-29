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
    $data['title'] = array(
      '#type' => 'atomium_html_tag',
      '#theme_hook_suggestion_parts' => array(
        $variables['theme_hook_original'],
      ),
      '#tag' => 'h3',
      '#attributes' => array(
        'class' => 'element-invisible',
      ),
      'title' => $data['title'],
    );
  }
}
