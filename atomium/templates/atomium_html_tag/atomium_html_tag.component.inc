<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_atomium_html_tag(array $existing, $type, $theme, $path) {
  return array(
    'atomium_html_tag' => array(
      'render element' => 'element',
      'template' => 'atomium-html-tag',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_atomium_html_tag(array &$variables, $hook) {
  // We do not use $variables['attributes'] because in template_process()
  // Drupal overrides the 'attributes' key property.
  $variables['atomium_attributes'] = $variables['atomium']['attributes']['element']
    ->setAttributes($variables['element']['#attributes']);
}
