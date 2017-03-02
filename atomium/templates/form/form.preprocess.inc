<?php

/**
 * @file
 * form.preprocess.inc
 */

/**
 * Implements hook_preprocess_form().
 */
function atomium_preprocess_form(&$variables) {
  $variables['theme_hook_suggestions'][] = 'form--' . $variables['element']['#form_id'];
}
