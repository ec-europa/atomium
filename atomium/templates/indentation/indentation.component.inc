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
function atomium_preprocess_indentation(array &$variables, $hook) {
  $size = $variables['size'];

  if (!\is_numeric($variables['size']) || $variables['size'] <= 0) {
    $size = 0;
  }

  $indentation = array(
    '#theme' => 'item_list',
    '#wrapper' => FALSE,
    '#type' => FALSE,
    '#items' => \array_fill(
      0,
      $size,
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
  );

  _atomium_extend_theme_property(
    $indentation,
    array($variables['theme_hook_original'], 'size' . $size));

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $indentation,
  );
}
