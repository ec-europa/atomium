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
        'fill' => '&nbsp;',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_indentation(&$variables, $hook) {
  if ($variables['size'] <= 0) {
    return;
  }

  $variables[$hook] = array(
    $hook => array(
      '#theme' => array('item_list'),
      '#wrapper' => FALSE,
      '#type' => FALSE,
      '#items' => array_fill(
        0,
        $variables['size'],
        array(
          '#type' => 'container',
          '#attributes' => array(
            'class' => array(
              'indentation',
            ),
          ),
          array(
            '#markup' => $variables['fill'],
          ),
        )
      ),
    ),
  );
}
