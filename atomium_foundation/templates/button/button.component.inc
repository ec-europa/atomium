<?php

/**
 * @file
 * Button.preprocess.inc.
 */

/**
 * Implements hook_preprocess_button().
 */
function atomium_foundation_preprocess_button(&$variables) {
  $variables['attributes_array']['class'][] = 'button';

  if (isset($variables['element']['#id']) && $id = $variables['element']['#id']) {
    list($id,) = explode('--', $id);
    switch ($id) {
      case 'edit-submit':
      case 'edit-update':
      case 'edit-save':
        $variables['attributes_array']['class'][] = 'primary';
        $variables['attributes_array']['class'][] = 'expanded';
        break;

      case 'edit-delete':
      case 'edit-delete_translation':
        $variables['attributes_array']['class'][] = 'alert';
        break;

      default:
        $variables['attributes_array']['class'][] = 'secondary';
    }
  }

  if (isset($variables['attributes_array']['value']) && t('Delete') == $variables['attributes_array']['value']) {
    $variables['attributes_array']['class'] = array_diff(
      $variables['attributes_array']['class'],
      array('primary', 'alert', 'secondary')
    );
    $variables['attributes_array']['class'][] = 'alert';
  }

  // The close-button is only used in status_messages.
  if (isset($variables['element']['#name']) && 'close-button' == $variables['element']['#name']) {
    $variables['attributes_array']['class'] = array_diff(
      $variables['attributes_array']['class'],
      array('primary', 'alert', 'secondary', 'button')
    );
  }
}
