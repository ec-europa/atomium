<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_bootstrap_preprocess_pager(&$variables, $hook) {
  $variables['pager']['#attributes']['class'][] = 'pagination';

  $variables['pager']['#wrapper'] = FALSE;
  $variables['pager']['#theme_wrappers'][] = 'html_tag__' . $variables['theme_hook_original'];
  $variables['pager']['#tag'] = 'nav';

  if (isset($variables['pager']['#items'])) {

    if ($variables['pager']['#items']['pager-current']['#markup']) {
      $markup = $variables['pager']['#items']['pager-current']['#markup'];
      $variables['pager']['#items']['pager-current'] = array(
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
