<?php

/**
 * @file
 * form_element_label.preprocess.inc
 */

/**
 * Implements hook_preprocess_form_element_label().
 */
function atomium_preprocess_form_element_label(&$variables, $hook) {
  $element = &$variables['element'];
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

  $variables['title'] = $t(filter_xss_admin($element['#title']));

  // TODO: See how we can improve this.
  $variables['required'] = '';
  if ($variables['element']['#required']) {
    $variables['required'] = array(
      '#theme' => 'form_required_marker',
      '#title' => '*',
    );
  }

  if (isset($variables['element']['#parents'])) {
    $parents = implode('__', $variables['element']['#parents']);
    $variables['theme_hook_suggestions'][] = $hook . '__form-element-' . $parents;
  }

  if (isset($variables['element']['#name'])) {
    $variables['attributes_array']['class'][] = 'hook__' . $hook . '__' . $variables['element']['#name'];
  }
}
