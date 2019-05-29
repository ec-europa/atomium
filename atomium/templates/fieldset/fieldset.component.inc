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

  // <legend> tag handling.
  $legend = '';
  if ($variables['title'] !== '') {
    $legend = array(
      '#type' => 'atomium_html_tag',
      '#tag' => 'legend',
      '#theme_hook_suggestions_parts' => array(
        $variables['theme_hook_original'],
      ),
      'content' => array(
        '#type' => 'atomium_html_tag',
        '#tag' => 'span',
        '#theme_hook_suggestions_parts' => array(
          $variables['theme_hook_original'],
        ),
        '#attributes' => array(
          'class' => array(
            'fieldset-legend',
          ),
        ),
        'value' => array(
          '#markup' => $variables['title'],
        ),
      ),
    );
  }
  $variables['legend'] = $legend;

  // Fieldset description handling.
  $description = '';
  if ($variables['description']) {
    $description = array(
      '#type' => 'atomium_html_tag',
      '#tag' => 'div',
      '#theme_hook_suggestions_parts' => array(
        $variables['theme_hook_original'],
        'description',
      ),
      '#attributes' => array(
        'class' => array(
          'fieldset-description',
        ),
      ),
      'value' => array(
        '#markup' => $variables['description'],
      ),
    );
  }
  $variables['description'] = $description;
}
