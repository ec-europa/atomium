<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_alter().
 */
function atomium_foundation_form_alter(&$form, &$form_state, $form_id) {
  if (!empty($form['actions'])) {
    $form['actions']['#attributes']['class'] = array('button-group', 'expanded');
    if (!empty($form['actions']['submit'])) {
      $form['actions']['submit']['#attributes']['class'][] = 'primary';
      $form['actions']['submit']['#attributes']['class'][] = 'button';
      $form['actions']['submit']['#attributes']['class'][] = 'radius';
    }
    if (!empty($form['actions']['preview'])) {
      $form['actions']['preview']['#attributes']['class'][] = 'secondary';
      $form['actions']['preview']['#attributes']['class'][] = 'button';
      $form['actions']['preview']['#attributes']['class'][] = 'radius';
    }
    if (!empty($form['actions']['delete_translation'])) {
      $form['actions']['delete_translation']['#attributes']['class'][] = 'warning';
      $form['actions']['delete_translation']['#attributes']['class'][] = 'button';
      $form['actions']['delete_translation']['#attributes']['class'][] = 'radius';
    }
    if (!empty($form['actions']['delete'])) {
      $form['actions']['delete']['#attributes']['class'][] = 'warning';
      $form['actions']['delete']['#attributes']['class'][] = 'button';
      $form['actions']['delete']['#attributes']['class'][] = 'radius';
    }
    if (!empty($form['actions']['save'])) {
      $form['actions']['save']['#attributes']['class'][] = 'primary';
      $form['actions']['save']['#attributes']['class'][] = 'button';
      $form['actions']['save']['#attributes']['class'][] = 'radius';
    }
    if (!empty($form['actions']['cancel'])) {
      $form['actions']['cancel']['#attributes']['class'][] = 'warning';
      $form['actions']['cancel']['#attributes']['class'][] = 'button';
      $form['actions']['cancel']['#attributes']['class'][] = 'radius';
    }
  }

  // Search Block Fixes.
  if (isset($form['#form_id']) && ($form['#form_id'] == 'search_block_form')) {
    $form['search_block_form']['#attributes']['class'][] = 'small-8';
    $form['search_block_form']['#attributes']['class'][] = 'columns';

    $form['actions']['submit']['#attributes']['class'][] = 'postfix';
    $form['actions']['submit']['#attributes']['class'][] = 'small-4';
    $form['actions']['submit']['#attributes']['class'][] = 'columns';
  }

  if (!empty($form['basic']['submit'])) {
    $form['basic']['submit']['#attributes']['class'][] = 'primary';
    $form['basic']['submit']['#attributes']['class'][] = 'button';
    $form['basic']['submit']['#attributes']['class'][] = 'radius';
    $form['basic']['keys']['#title'] = '';
    $form['basic']['keys']['#attributes']['placeholder'] = t('Search');
  }
}
