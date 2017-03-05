<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_foundation_preprocess_mark(&$variables) {
  $variables['attributes_array']['class'][] = 'label';
  $variables['attributes_array']['class'][] = 'info';

  if (!empty($variables['title'])) {
    $variables['title'] = array(
      array(
        '#theme' => 'html_tag__' . $variables['theme_hook_original'],
        '#tag' => 'i',
        '#attributes' => array(
          'class' => array(
            'fi-info',
          ),
        ),
      ),
      array(
        '#markup' => $variables['title'],
      ),
    );
  }
}
