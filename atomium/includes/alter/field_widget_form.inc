<?php

/**
 * @file
 * field_widget_form.inc
 */

/**
 * Implements hook_field_widget_form_alter().
 */
function atomium_field_widget_form_alter(&$element, &$form_state, $context) {
  $element['#description'] = '';

  if (isset($element['#description'])) {
    $description = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#attributes' => array(
        'class' => array(
          'help-text',
        ),
      ),
      'text' => array(
        '#type' => 'markup',
        '#markup' => $element['#description'],
      ),
    );

    $element['#description'] = render($description);
  }

}
