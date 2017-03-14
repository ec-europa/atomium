<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_foundation_preprocess_mark(&$variables, $hook) {
  $variables['attributes_array']['class'][] = 'label';
  $variables['attributes_array']['class'][] = 'info';

  $variables[$hook] = '';
  if (!empty($variables['title'])) {
    $variables[$hook] = array(
      'content' => array(
        'icon' => array(
          '#theme' => 'html_tag',
          '#tag' => 'i',
          '#attributes' => array(
            'class' => array(
              'fi-info',
            ),
          ),
        ),
        'title' => array(
          '#markup' => $variables['title'],
        ),
      ),
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'span',
      '#attributes' => $variables['attributes_array'],
    );
  }
}
