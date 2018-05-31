<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
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
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_form_element_label(array &$variables, $hook) {
  $element = &$variables['element']['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $variables['atomium']['attributes']['wrapper']->append('class', 'option');
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $variables['atomium']['attributes']['wrapper']->append('class', 'element-invisible');
  }

  if (!empty($element['#id'])) {
    $variables['atomium']['attributes']['wrapper']->append('for', $element['#id']);
  }

  $variables += array(
    'title' => '',
    'required' => '',
  );
  if (isset($element['#title']) && !empty($element['#title'])) {
    $variables['title'] = array(
      '#markup' => $t(filter_xss_admin($element['#title'])),
    );
  }

  if (isset($element['#required']) && $element['#required']) {
    $variables['required'] = array(
      '#theme' => _atomium_extend_theme_hook('form_required_marker', $variables['theme_hook_original']),
    );
  }

  $variables[$variables['base_hook']] = array(
    'title' => array(
      $variables['title'],
    ),
    'required' => array(
      $variables['required'],
    ),
  );
}
