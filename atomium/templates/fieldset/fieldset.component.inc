<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_fieldset(array $existing, $type, $theme, $path) {
  return array(
    'fieldset' => array(
      'render element' => 'element',
      'template' => 'fieldset',
    ),
  );
}

/**
 * Implements hook_atomium_definition_hook().
 */
function atomium_atomium_definition_fieldset() {
  return array(
    'label' => 'Fieldset',
    'description' => 'Fieldset.',
    'preview' => array(
      'fieldset' => array(
        'title' => 'Fieldset title',
        'description' => 'Fieldset description.',
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_fieldset(array &$variables, $hook) {
  $variables += array(
    'description' => '',
  );

  $variables['title'] = '';
  if (isset($variables['element']['#title'])) {
    $variables['title'] = $variables['element']['#title'];
  }
  if (!empty($variables['element']['#description'])) {
    $variables['description'] = $variables['element']['#description'];
  }
  if (isset($variables['element']['#id'])) {
    $variables['atomium']['attributes']['wrapper']->append('id', $variables['element']['#id']);
  }
  $variables['atomium']['attributes']['wrapper']->append('class', 'form-wrapper');
  $variables['atomium']['attributes']['wrapper']->merge($variables['element']['#attributes']);

  /* <legend> tag handling */
  $legend = '';
  if ($variables['title']) {
    $legend = array(
      'content' => array(
        '#markup' => $variables['title'],
        '#theme_wrappers' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original']),
        '#tag' => 'span',
        '#attributes' => array(
          'class' => array(
            'fieldset-legend',
          ),
        ),
      ),
      '#theme_wrappers' => _atomium_extend_theme_hook('html_tag', array('legend', $variables['theme_hook_original'])),
      '#tag' => 'legend',
      '#attributes' => array(),
    );
  }
  $variables['legend'] = $legend;

  /* Fieldset description handling */
  $description = '';
  if ($variables['description']) {
    $description = array(
      '#markup' => $variables['description'],
      '#theme_wrappers' => _atomium_extend_theme_hook('html_tag', $variables['theme_hook_original'] . '__description'),
      '#tag' => 'div',
      '#attributes' => array(
        'class' => array(
          'fieldset-description',
        ),
      ),
    );
  }
  $variables['description'] = $description;
}
