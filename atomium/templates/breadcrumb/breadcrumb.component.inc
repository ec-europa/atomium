<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_breadcrumb() {
  return array(
    'breadcrumb' => array(
      'variables' => array('breadcrumb' => NULL),
      'template' => 'breadcrumb',
    ),
  );
}

/**
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_atomium_definition_breadcrumb() {
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
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_breadcrumb(&$variables, $hook) {
  $variables[$hook] = array(
    $hook => array(
      '#theme' => 'item_list__' . $variables['theme_hook_original'],
      '#items' => $variables['breadcrumb'],
      '#type' => 'ul',
      '#attributes' => $variables['attributes_array'],
      '#context' => array(
        'parents' => array(
          $hook => $variables,
        ),
      ),
    ),
    '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original']),
    '#tag' => 'nav',
    '#attributes' => $variables['wrapper_attributes_array'],
  );
}
