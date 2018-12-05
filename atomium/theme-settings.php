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
    '#title'         => t('Enable theme debug ?'),
    '#default_value' => theme_get_setting('theme_debug'),
    '#description'   => t('Theme debug mode can be used to see possible template suggestions and the locations of template files right in your HTML markup (as HTML comments). For more information, see <a href="@url">documentation</a>.', array('@url' => 'https://www.drupal.org/docs/7/theming/overriding-themable-output/working-with-template-suggestions')),
  );
  $form['atomium']['atomium_rebuild_registry'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Rebuild the theme registry at each page load ?'),
    '#default_value' => theme_get_setting('atomium_rebuild_registry'),
    '#description'   => t('Auto-rebuild the theme registry during development. It is <em>extremely</em> important to <a href="!link">turn off this feature</a> on production websites.', array('@link' => url('admin/appearance/settings/' . $GLOBALS['theme']))),
  );
  $form['atomium']['allow_css_double_underscores'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Allow CSS double underscore ?'),
    '#default_value' => theme_get_setting('allow_css_double_underscores'),
    '#description' => t('In order to allow CSS identifiers to contain double underscores for Drupal\'s BEM-style naming standards, this variable can be set to TRUE. For more information, see <a href="@url">documentation</a>.', array('@url' => 'https://www.drupal.org/node/2810369')),
  );
}
