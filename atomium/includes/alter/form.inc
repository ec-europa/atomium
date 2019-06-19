<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_alter().
 */
function atomium_form_alter(array &$form, array &$form_state, $form_id) {
  $form += array(
    '#pre_render' => array(),
  );

  $form['#pre_render'] = array_merge(
    $form['#pre_render'],
    array(
      '_atomium_form_alter_pre_render' => '_atomium_form_alter_pre_render',
      'atomium_pre_render_form_bug_3056608' => 'atomium_pre_render_form_bug_3056608',
    )
  );
}

/**
 * Custom pre_render callback.
 *
 * @param array $element
 *   The element to alter.
 *
 * @return array
 *   The element altered.
 */
function _atomium_form_alter_pre_render(array $element) {
  $context = array(
    'form' => $element,
    'suggestions parts' => array(
      $element['#id'],
    ),
  );

  _atomium_add_default_pre_render_variables($element);

  atomium_recursive_element_children(
    $element,
    function (&$element, $element_key, &$recursive_context) use ($context) {
      _atomium_add_default_pre_render_variables($element);

      $element['#atomium']['suggestions']['theme'] = array_merge(
        array_filter(array_keys($recursive_context['parents'])),
        $context['suggestions parts'],
        $element['#atomium']['suggestions']['theme']
      );

      $type = array();
      if (isset($element['#type'])) {
        $type[] = $element['#type'];

        if (isset($element['#theme'])) {
          if ($element['#theme'] !== $element['#type']) {
            $type = array_merge(
              $type,
              (array) $element['#theme']
            );
          }
        }
      }

      $element['#atomium']['suggestions']['theme_wrappers'] = array_merge(
        $type,
        array_filter(array_keys($recursive_context['parents'])),
        $context['suggestions parts'],
        $element['#atomium']['suggestions']['theme_wrappers']
      );
    },
    NULL,
    $context
  );

  return $element;
}

/**
 * Custom pre_render callback.
 *
 * Prevent user-facing field styling from screwing up node edit forms by
 * renaming the classes on the node edit form's field wrappers.
 *
 * To be removed if #1245218 is backported to Drupal 7.
 *
 * @param array $element
 *   The element to alter.
 *
 * @return array
 *   The element altered.
 */
function atomium_pre_render_form_bug_3056608(array $element) {
  foreach (\array_keys($element) as $item) {
    if (\strpos($item, 'field_') !== 0) {
      continue;
    }

    if (empty($element[$item]['#attributes']['class'])) {
      continue;
    }

    foreach ($element[$item]['#attributes']['class'] as &$class) {
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

  return $element;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function atomium_form_search_block_form_alter(array &$form, array &$form_state, $form_id) {
  $form['search_block_form']['#attributes']['type'] = 'search';
}
