<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_search_block_form_alter(array &$form, array &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['type'] = 'search';
}
