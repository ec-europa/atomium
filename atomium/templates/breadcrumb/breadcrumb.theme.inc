<?php

/**
 * @file
 * breadcrumb.theme.inc
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__breadcrumb() {
  return array(
    'breadcrumb' => array(
      'variables' => array('breadcrumb' => NULL),
      'template' => 'breadcrumb',
    ),
  );
}

/**
 * Implements THEME_atomium_overview__HOOK().
 */
function atomium_atomium_overview__breadcrumb() {
  return array(
    'label' => 'Breadcrumb',
    'description' => 'Site breadcrumb.',
    'preview' => array(
      'breadcrumb' => array(
        l(t('Home'), '/'),
        l(t('News'), '/'),
        t('My news title'),
      ),
    ),
  );
}
