<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_bootstrap_preprocess_pager(&$variables, $hook) {
  $variables[$hook][$hook]['#attributes']['class'][] = 'pagination';

  $variables[$hook][$hook]['#wrapper'] = FALSE;
  $variables[$hook][$hook]['#theme_wrappers'][] = 'html_tag__' . $variables['theme_hook_original'];
  $variables[$hook][$hook]['#tag'] = 'nav';

  if (isset($variables[$hook][$hook]['#items'])) {

    if ($variables[$hook][$hook]['#items']['pager_current']['#markup']) {
      $markup = $variables[$hook][$hook]['#items']['pager_current']['#markup'];
      $variables[$hook][$hook]['#items']['pager_current'] = array(
        'link' => array(
          '#theme' => 'link',
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
          'html_tag__' . $variables['theme_hook_original'],
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
