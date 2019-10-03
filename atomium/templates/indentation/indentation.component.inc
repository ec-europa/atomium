<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_indentation(array $existing, $type, $theme, $path) {
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
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_indentation() {
  return array(
    'label' => 'Indentation',
    'description' => 'Indentation description.',
    'preview' => array(
      'size' => 4,
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

  $item = array(
    '#type' => 'container',
    '#theme_wrappers' => array('container'),
    '#attributes' => array(
      'class' => array(
        'indentation',
      ),
    ),
    array(
      '#markup' => $variables['fill'],
    ),
  );

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        array('size' . $size, $variables['theme_hook_original'])
      ),
      '#wrapper' => FALSE,
      '#type' => FALSE,
      '#items' => \array_fill(
        0,
        $size,
        $item
      ),
    ),
  );
}
