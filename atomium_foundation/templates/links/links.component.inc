<?php

/**
 * @file
 * Links.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_links(&$variables, $hook) {
  if (in_array($variables['theme_hook_original'], array('links__contextual'))) {
    return;
  }

  $variables[$hook][$hook]['#wrapper'] = FALSE;
  $variables[$hook][$hook]['#type'] = 'div';
  $variables[$hook][$hook]['#attributes']['class'][] = 'small';
  $variables[$hook][$hook]['#attributes']['class'][] = 'expanded';
  $variables[$hook][$hook]['#attributes']['class'][] = 'secondary';
  $variables[$hook][$hook]['#attributes']['class'][] = 'button-group';

  if (isset($variables[$hook][$hook]['#items']) && is_array($variables[$hook][$hook]['#items'])) {
    foreach ($variables[$hook][$hook]['#items'] as &$item) {
      unset($item['#theme_wrappers']);
      unset($item['#tag']);
      $item['link']['#options']['attributes_array']['class'][] = 'button';
    }
  }
}
