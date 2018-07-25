<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_search_block_form_alter(array &$form, array &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['placeholder'][] = t('Search');
  $form['search_block_form']['#attributes']['type'] = 'search';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_login_block_alter(array &$form, array &$form_state, $form_id) {
  $form['name']['#attributes']['placeholder'][] = $form['name']['#title'];
  $form['pass']['#attributes']['placeholder'][] = $form['pass']['#title'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_register_form_alter(array &$form, array &$form_state, $form_id) {
  $form['account']['name']['#attributes']['placeholder'][] = $form['account']['name']['#title'];
  $form['account']['mail']['#attributes']['placeholder'][] = $form['account']['mail']['#title'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_login_alter(array &$form, array &$form_state, $form_id) {
  $form['name']['#attributes']['placeholder'][] = $form['name']['#title'];
  $form['pass']['#attributes']['placeholder'][] = $form['pass']['#title'];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_user_pass_alter(array &$form, array &$form_state, $form_id) {
  $form['name']['#attributes']['placeholder'][] = $form['name']['#title'];
}
