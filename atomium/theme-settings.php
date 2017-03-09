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

  $form['atomium']['theme_debug'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Theme debug'),
    '#default_value' => theme_get_setting('theme_debug'),
    '#description'   => t('Enable theme debug ?'),
  );
  $form['atomium']['allow_css_double_underscores'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Allow CSS double underscore'),
    '#default_value' => theme_get_setting('allow_css_double_underscores'),
  );
}
