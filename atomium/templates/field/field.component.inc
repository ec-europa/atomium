<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_field(array $existing, $type, $theme, $path) {
  return array(
    'field' => array(
      'render element' => 'element',
      'template' => 'field',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_field(array &$variables, $hook) {
  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        array(
          $variables['theme_hook_original'],
        )
      ),
      '#title' => $variables['label'],
      '#items' => $variables['items'],
      '#type' => 'div',
      '#atomium' => array(
        'attributes' => array(
          'wrapper' => array(
            'class' => $variables['classes_array'],
          ),
        ),
      ),
    ),
  );
}
