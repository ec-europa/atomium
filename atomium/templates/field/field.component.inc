<?php

/**
 * @file
 * Field.theme.inc.
 */

/**
 * Implements atomium_theme_alter__hook().
 */
function atomium_theme__field() {
  return array(
    'field' => array(
      'render element' => 'element',
      'template' => 'field',
    ),
  );
}

/**
 * Implements hook_preprocess_field().
 */
function atomium_preprocess_field(&$variables) {
  $variables += array('attributes_array' => array());
  $variables['attributes_array'] += array('class' => array());
  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
  $variables['content_attributes_array']['class'][] = 'field-items';

  $attributes_item = array();
  foreach ($variables['items'] as $delta => $item) {
    $classes = array('field-item ', ($delta % 2 ? 'odd' : 'even'));
    $attributes_item[$delta]['class'] = $classes;
    $attributes_item[$delta] = atomium_drupal_attributes($attributes_item[$delta]);
  }

  $variables['attributes_item'] = $attributes_item;
}
