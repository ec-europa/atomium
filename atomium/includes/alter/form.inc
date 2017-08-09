<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_alter().
 */
function atomium_form_alter(&$form, &$form_state, $form_id) {
  // Custom recursive function to alter all the #theme keys of form elements.
  _atomium_form_element_theme_alter($form, $form_state, $form_id);
}

/**
 * Custom callback.
 *
 * This function will alter all the element in a form and update their
 * #theme key to append the $form_id at the end so we can preprocess them.
 *
 * @see form_builder()
 */
function _atomium_form_element_theme_alter(&$form, &$form_state, $form_id) {
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['#type']) && empty($form[$key]['#defaults_loaded']) && ($info = element_info($form[$key]['#type']))) {
      if (isset($info['#theme'])) {
        // We must ensure lowercase values because get_defined_functions()
        // in drupal_group_functions_by_prefix() returns functions in
        // lower case.
        // @see http://php.net/manual/en/function.get-defined-functions.php
        $form[$key]['#theme'] = array(
          drupal_strtolower(
            implode(
              '__',
              array(
                $info['#theme'],
                $form_id,
                $key,
              )
            )
          ),
        );
      }
      if (isset($info['#theme_wrappers'])) {
        $form[$key] += array('#theme_wrappers' => array());
        $form[$key]['#theme_wrappers'] = array_merge($form[$key]['#theme_wrappers'], $info['#theme_wrappers']);
        $form[$key]['#theme_wrappers'] = array_map(function ($item) use ($form_id, $key) {
          // We must ensure lowercase values because get_defined_functions()
          // in drupal_group_functions_by_prefix() returns functions in
          // lower case.
          // @see http://php.net/manual/en/function.get-defined-functions.php
          //
          // It is better if the $form_id doesn't start with underscore.
          return drupal_strtolower($item . '__' . $form_id . '__' . $key);
        }, $info['#theme_wrappers']);
      }
    }

    _atomium_form_element_theme_alter($form[$key], $form_state, $form_id);
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_search_block_form_alter(&$form, &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['placeholder'][] = t('Search');
  $form['search_block_form']['#attributes']['type'] = 'search';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_login_block_alter(&$form, &$form_state, $form_id) {
  $form['name']['#attributes']['placeholder'][] = $form['name']['#title'];
  $form['pass']['#attributes']['placeholder'][] = $form['pass']['#title'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_register_form_alter(&$form, &$form_state, $form_id) {
  $form['account']['name']['#attributes']['placeholder'][] = $form['account']['name']['#title'];
  $form['account']['mail']['#attributes']['placeholder'][] = $form['account']['mail']['#title'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_login_alter(&$form, &$form_state, $form_id) {
  $form['name']['#attributes']['placeholder'][] = $form['name']['#title'];
  $form['pass']['#attributes']['placeholder'][] = $form['pass']['#title'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_pass_alter(&$form, &$form_state, $form_id) {
  $form['name']['#attributes']['placeholder'][] = $form['name']['#title'];
}
