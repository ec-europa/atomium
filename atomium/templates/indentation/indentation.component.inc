<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_indentation() {
  return array(
    'indentation' => array(
      'template' => 'indentation',
      'variables' => array(
        'size' => 1,
        'indentation' => '&nbsp;',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_indentation(&$variables, $hook) {
  $variables['indentation'] = array_fill(
    0,
    $variables['size'],
    array(
      '#markup' => $variables['indentation'],
    )
  );

  $variables['attributes_array']['class'][] = 'indentation';

  $variables[$hook] = '';
  if ($variables['size'] > 0) {
    $variables[$hook] = array(
      $hook => array(
        '#theme' => array('item_list'),
        '#type' => '',
        '#items' => $variables['indentation'],
        '#attributes' => array(
          'class' => array(
            'indentation',
            'size_' . $variables['size'],
          ),
        ),
      ),
      '#theme_wrappers' => array('container'),
      '#attributes' => $variables['attributes_array'],
    );
  }
}
