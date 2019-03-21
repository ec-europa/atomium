<?php

/**
 * @file
 * Contains theme-settings.php.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function atomium_form_system_theme_settings_alter(array &$form, array $form_state) {
  $form['atomium'] = array(
    '#type' => 'fieldset',
    '#title' => t('Atomium settings'),
    '#weight' => -1,
  );
  $form['atomium']['allow_css_double_underscores'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow CSS double underscore ?'),
    '#default_value' => theme_get_setting('allow_css_double_underscores'),
    '#description' => t('In order to allow CSS identifiers to contain double underscores for Drupal\'s BEM-style naming standards, this variable can be set to TRUE. For more information, see <a href="@url">documentation</a>.', array('@url' => 'https://www.drupal.org/node/2810369')),
  );
}
