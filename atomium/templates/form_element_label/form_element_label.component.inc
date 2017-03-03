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
      'template' => 'form-element-label',
      'variables' => array(
        'element' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
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

  $variables['title'] = '';
  if (isset($element['#title'])) {
    $variables['title'] = $t(filter_xss_admin($element['#title']));
  }

  // TODO: See how we can improve this.
  $variables['required'] = '';
  if (isset($variables['element']['#required']) && $variables['element']['#required'] == TRUE) {
    $variables['required'] = array(
      '#theme' => 'form_required_marker',
      '#element' => $variables['element'],
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
