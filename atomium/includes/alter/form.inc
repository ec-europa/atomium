<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_alter().
 */
function atomium_form_alter(array &$form, array &$form_state, $form_id) {
  $context = array(
    'form' => $form,
    'form_state' => $form_state,
    'form_id' => $form_id,
  );

  $callback = function (&$root_element, $root_element_key, $context) {
    if (!isset($root_element['#type'])) {
      return;
    }

    if (!empty($root_element['#defaults_loaded'])) {
      return;
    }

    $info = element_info($root_element['#type']);

    if (empty($info)) {
      return;
    }

    if (isset($info['#theme'])) {
      if (!isset($root_element['#theme'])) {
        $root_element['#theme'] = $info['#theme'];
      }

      $root_element['#theme'] = _atomium_extend_with_suggestions(
        (array) $root_element['#theme'],
        array('form', $context['form_id'], $root_element_key)
      );
    }

    if (isset($info['#theme_wrappers'])) {
      if (!isset($root_element['#theme_wrappers'])) {
        $root_element['#theme_wrappers'] = $info['#theme_wrappers'];
      }

      $root_element['#theme_wrappers'] = _atomium_extend_with_suggestions(
        $root_element['#theme_wrappers'],
        array('form', $context['form_id'], $root_element_key)
      );
    }
  };

  _atomium_recursive_element_children(
    $form,
    $callback,
    NULL,
    $context
  );

  /*
   * Prevent user-facing field styling from screwing up node edit forms by
   * renaming the classes on the node edit form's field wrappers.
   *
   * Remove if #1245218 is backported to D7 core.
   */
  foreach (\array_keys($form) as $item) {
    if (\strpos($item, 'field_') !== 0) {
      continue;
    }

    if (empty($form[$item]['#attributes']['class'])) {
      continue;
    }

    foreach ($form[$item]['#attributes']['class'] as &$class) {
      // Core bug: the field-type-text-with-summary class
      // is used as a JS hook.
      if ($class === 'field-type-text-with-summary') {
        continue;
      }

      if (\strpos($class, 'field-type-') !== 0) {
        continue;
      }

      if (\strpos($class, 'field-name-') !== 0) {
        continue;
      }

      // Make the class different from what used in theme_field().
      $class = 'form-' . $class;
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_search_block_form_alter(array &$form, array &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['type'] = 'search';
}
