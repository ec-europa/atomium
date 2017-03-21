<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_europa_atomium_theme_page_header() {
  return array(
    'page_header' => array(
      'variables' => array(
        'markup' => NULL,
      ),
      'template' => 'page-header',
    ),
  );
}

/**
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_europa_atomium_definition_page_header() {
  return array(
    'label' => 'Page header',
    'description' => 'Page header.',
    'preview' => array(
      'markup' => '<p>The <strong>European Commission</strong> is the European Union’s executive body. It represents the interests of the European Union as a whole.</p>',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_europa_preprocess_page_header(&$variables, $hook) {
  $variables[$hook] = array(
    $hook => array(
      '#markup' => $variables['markup'],
    ),
  );
}
