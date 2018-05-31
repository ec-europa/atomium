<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bootstrap_preprocess_pager(array &$variables, $hook) {
  $variables[$hook][$hook]['#attributes']['class'][] = 'pagination';

  $variables[$hook][$hook]['#wrapper'] = FALSE;
  $variables[$hook][$hook]['#theme_wrappers'][] = 'html_tag';
  $variables[$hook][$hook]['#tag'] = 'nav';

  if (isset($variables[$hook][$hook]['#items'])) {

    if ($variables[$hook][$hook]['#items']['pager_current']['#markup']) {
      $markup = $variables[$hook][$hook]['#items']['pager_current']['#markup'];
      $variables[$hook][$hook]['#items']['pager_current'] = array(
        'link' => array(
          '#theme' => array('link'),
          '#text' => array(
            '#markup' => $markup,
          ),
          '#path' => current_path(),
          '#options' => array(
            'attributes' => array(
              'active',
            ),
          ),
        ),
        '#theme_wrappers' => array(
          'html_tag',
        ),
        '#tag' => 'li',
        '#attributes' => array(
          'class' => array(
            'active',
          ),
        ),
      );
    }
  }
}
