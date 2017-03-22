<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_form_element_label() {
  return array(
    'form_element_label' => array(
      'render element' => 'element',
      'template' => 'form-element-label',
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_form_element_label(&$variables, $hook) {
  $element = &$variables['element'][$hook];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $variables['attributes_array']['class'][] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $variables['attributes_array']['class'][] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $variables['attributes_array']['for'][] = $element['#id'];
  }

  $variables['title'] = '';
  if (isset($element['#title'])) {
    $variables['title'] = array(
      '#markup' => $t(filter_xss_admin($element['#title'])),
    );
  }

  // TODO: See how we can improve this.
  $variables['required'] = '';
  if (isset($element['#required']) && $element['#required'] == TRUE) {
    $variables['required'] = array(
      '#theme' => array('form_required_marker'),
      '#element' => $variables['element'],
    );
  }

  if (isset($variables['element']['#name'])) {
    $variables['attributes_array']['class'][] = 'hook__' . $hook . '__' . $variables['element']['#name'];
  }

  $variables[$hook] = array(
    'title' => array(
      $variables['title'],
    ),
    'required' => array(
      $variables['required'],
    ),
  );
}
