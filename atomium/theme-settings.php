<?php

/**
 * @file
 * Contains theme-settings.php.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function atomium_form_system_theme_settings_alter(&$form, $form_state) {
  $form['atomium'] = array(
    '#type' => 'fieldset',
    '#title' => t('Atomium settings'),
    '#weight' => -1,
  );
  $form['atomium']['allow_css_double_underscores'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Allow CSS double underscore ?'),
    '#default_value' => theme_get_setting('allow_css_double_underscores'),
    '#description' => t('In order to allow CSS identifiers to contain double underscores for Drupal\'s BEM-style naming standards, this variable can be set to TRUE. For more information, see <a href="@url">documentation</a>.', array('@url' => 'https://www.drupal.org/node/2810369')),
  );
  $form['atomium']['atomium_convert_inline_js_into_files'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Move inline Javascript into files ?'),
    '#default_value' => theme_get_setting('atomium_convert_inline_js_into_files'),
    '#description' => t('Atomium allows you to move inline Javascript (like the Drupal settings) into a file that is automatically loaded as a regular JS file.'),
  );
}
