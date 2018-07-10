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
        '#theme_wrappers' => array('html_tag'),
        '#tag' => 'span',
        '#attributes' => array(
          'class' => array(
            'fieldset-legend',
          ),
        ),
      ),
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'legend',
      '#attributes' => array(),
    );

    _atomium_extend_theme_wrappers_property(
      $legend,
      array($legend['#tag'], $variables['theme_hook_original']));

    _atomium_extend_theme_wrappers_property(
      $legend['content'],
      array(
        $legend['content']['#tag'],
        $legend['#tag'],
        $variables['theme_hook_original'],
      )
    );
  }
  $variables['legend'] = $legend;

  /* Fieldset description handling */
  $description = '';
  if ($variables['description']) {
    $description = array(
      '#markup' => $variables['description'],
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'div',
      '#attributes' => array(
        'class' => array(
          'fieldset-description',
        ),
      ),
    );

    _atomium_extend_theme_wrappers_property(
      $description,
      array(
        $description['#tag'],
        $variables['theme_hook_original'],
        'description',
      )
    );
  }
  $variables['description'] = $description;
}
