<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_options_none() {
  return array(
    'options_none' => array(
      'template' => 'options-none',
      'variables' => array('instance' => NULL, 'option' => NULL),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_options_none(&$variables, $hook) {
  $instance = $variables['instance'];
  $option = $variables['option'];

  $output = '';
  switch ($instance['widget']['type']) {
    case 'options_buttons':
      $output = t('N/A');
      break;

    case 'options_select':
      $output = ($option == 'option_none' ? t('- None -') : t('- Select a value -'));
      break;
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#markup' => $output,
    ),
  );
}
