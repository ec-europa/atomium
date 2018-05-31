<?php

/**
 * @file
 * Button.preprocess.inc.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_foundation_preprocess_button(array &$variables, $hook) {
  $variables['atomium']['attributes']['element']->append('class', 'button');

  if (isset($variables['element']['#id']) && $id = $variables['element']['#id']) {
    list($id,) = explode('--', $id);
    switch ($id) {
      case 'edit-submit':
      case 'edit-update':
      case 'edit-save':
        $variables['atomium']['attributes']['wrapper']->append('class', array('primary', 'expanded'));
        break;

      case 'edit-delete':
      case 'edit-delete_translation':
        $variables['atomium']['attributes']['wrapper']->append('class', 'alert');
        break;

      default:
        $variables['atomium']['attributes']['wrapper']->append('class', 'secondary');
    }
  }

  if (isset($variables['element']['#value']) && t('Delete') == $variables['element']['#value']) {
    $variables['atomium']['attributes']['element']->remove('class', array('primary', 'secondary'))->append('class', 'alert');
  }

  // The close-button is only used in status_messages.
  if (isset($variables['element']['#name']) && 'close-button' == $variables['element']['#name']) {
    $variables['atomium']['attributes']['element']
      ->remove(
    'class', array('primary', 'alert', 'secondary', 'button')
      )
      ->append('class', 'alert');
  }
}
