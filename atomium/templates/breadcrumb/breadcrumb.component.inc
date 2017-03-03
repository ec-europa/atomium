<?php

/**
 * @file
 * Breadcrumb.theme.inc.
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

/**
 * Implements hook_preprocess_breadcrumb().
 */
function atomium_preprocess_breadcrumb(&$variables) {
  $variables['links'] = array(
    '#theme' => 'item_list',
    '#items' => $variables['breadcrumb'],
    '#type' => 'ul',
    '#attributes' => $variables['attributes_array'],
  );
}
