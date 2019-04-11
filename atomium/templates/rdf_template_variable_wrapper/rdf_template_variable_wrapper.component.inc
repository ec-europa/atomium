<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_rdf_template_variable_wrapper(array $existing, $type, $theme, $path) {
  return array(
    'rdf_template_variable_wrapper' => array(
      'template' => 'rdf-template-variable-wrapper',
      'variables' => array(
        'content' => NULL,
        'attributes' => array(),
        'context' => array(),
        'inline' => TRUE,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_rdf_template_variable_wrapper(array &$variables, $hook) {
  $rdf_template_variable_wrapper = array(
    '#markup' => $variables['content'],
  );

  if (!empty($rdf_template_variable_wrapper['#markup']) && !empty($variables['attributes'])) {
    $variables['atomium']['attributes']['wrapper']->import($variables['attributes']);

    $rdf_template_variable_wrapper = array(
      '#theme' => 'html_tag',
      '#tag' => $variables['inline'] ? 'span' : 'div',
      '#attributes' => $variables['atomium']['attributes']['wrapper']->getValuesAsArray(),
      'content' => $rdf_template_variable_wrapper,
    );

    _atomium_extend_theme_property(
      $rdf_template_variable_wrapper,
      array($variables['theme_hook_original'])
    );
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $rdf_template_variable_wrapper,
  );
}
