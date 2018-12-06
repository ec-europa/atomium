<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_ID_alter().
 */
function atomium_bootstrap_form_system_theme_settings_alter(array &$form, array &$form_state = array(), $form_id = NULL) {
  // Create vertical tabs for global settings (provided by core or other
  // contrib modules).
  if (!isset($form['global'])) {
    $form['global'] = array(
      '#type' => 'vertical_tabs',
      '#weight' => -9,
    );
    if (!empty($form_state['build_info']['args'][0])) {
      $form['global']['#prefix'] = '<h2><small>' . t('Override Global Settings') . '</small></h2>';
    }
  }

  // Iterate over all child elements and check to see if they should be
  // moved in the global vertical tabs.
  $global_children = element_children($form);
  foreach ($global_children as $child) {
    if (isset($form[$child]['#type']) && 'fieldset' === $form[$child]['#type'] && !isset($form[$child]['#group'])) {
      $form[$child]['#group'] = 'global';
    }
  }
}

/**
 * Implements hook_form_ID_alter().
 */
function atomium_bootstrap_form_search_form_alter(array &$form, array &$form_state = array(), $form_id = NULL) {
  // Remove container-inline from the container classes.
  $form['basic']['#attributes']['class'] = array();

  // Hide the default button from display.
  $form['basic']['submit']['#attributes']['class'][] = 'element-invisible';

  // Implement a theme wrapper to add a submit button containing a search
  // icon directly after the input element.
  $form['basic']['keys']['#title'] = '';
  $form['basic']['keys']['#attributes']['placeholder'] = t('Search');
}

/**
 * Implements hook_form_ID_alter().
 */
function atomium_bootstrap_form_search_block_form_alter(array &$form, array &$form_state = array(), $form_id = NULL) {
  $form['#attributes']['class'][] = 'form-search';

  $form['search_block_form']['#title'] = '';
  $form['search_block_form']['#attributes']['placeholder'] = t('Search');

  // Hide the default button from display and implement a theme wrapper
  // to add a submit button containing a search icon directly after the
  // input element.
  $form['actions']['submit']['#attributes']['class'][] = 'element-invisible';
  // Apply a clearfix so the results don't overflow onto the form.
  $form['#attributes']['class'][] = 'content-search';
}

/**
 * Implements hook_form_ID_alter().
 */
function atomium_bootstrap_form_image_style_form_alter(array &$form, array &$form_state = array(), $form_id = NULL) {
  $form['effects']['new']['new']['#input_group_button'] = TRUE;
}

/**
 * Implements hook_form_ID_alter().
 */
function atomium_bootstrap_form_path_admin_filter_form_alter(array &$form, array &$form_state = array(), $form_id = NULL) {
  $form['basic']['filter']['#input_group_button'] = TRUE;
}
