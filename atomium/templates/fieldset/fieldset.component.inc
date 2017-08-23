<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_fieldset() {
  return array(
    'fieldset' => array(
      'render element' => 'element',
      'template' => 'fieldset',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_fieldset(&$variables) {
  $variables += array(
    'attributes_array' => array(),
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
    $variables['attributes_array']['id'] = $variables['element']['#id'];
  }
  $variables['attributes_array']['class'][] = 'form-wrapper';
  $variables['attributes_array'] = drupal_array_merge_deep(
    $variables['element']['#attributes'],
    $variables['attributes_array']
  );

  /* <legend> tag handling */
  $legend = '';
  if ($variables['title']) {
    $legend = array(
      'content' => array(
        '#markup' => $variables['title'],
        '#theme_wrappers' => array('html_tag'),
        '#tag' => 'span',
        '#attributes' => array(
          'class' => array(
            'fieldset-legend',
          ),
        ),
      ),
      '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original'] . '__legend'),
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
      '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original'] . '__description'),
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
