<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_form_element_mark() {
  return array(
    'form_element_mark' => array(
      'render element' => 'element',
      'template' => 'form-required-marker',
      'variables' => array(
        'element' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_form_required_marker(&$variables, $hook) {
  $t = get_t();

  $attributes = array(
    'class' => array(
      'form-required',
    ),
    'title' => $t('This field is required.'),
  );

  $variables['title'] = '*';
  if (isset($variables['element']['#field_name'])) {
    $variables['theme_hook_suggestions'][] = 'form_required_marker__' . $variables['element']['#field_name'];
  }

  if (isset($variables['element']['#parents'])) {
    $parents = implode('__', $variables['element']['#parents']);
    $variables['theme_hook_suggestions'][] = $hook . '__form-element--' . $parents;
  }

  if (isset($variables['element']['#name'])) {
    $attributes['class'] = 'hook__' . $hook . '__' . $variables['element']['#name'];
  }

  $variables['attributes_array'] = drupal_array_merge_deep($variables['attributes_array'], $attributes);

  $variables[$hook] = $variables['title'];
}
