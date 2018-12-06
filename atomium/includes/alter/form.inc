<?php

/**
 * @file
 * form.inc
 */

/**
 * Implements hook_form_alter().
 */
function atomium_form_alter(array &$form, array &$form_state, $form_id) {
  // Custom recursive function to alter all the #theme keys of form elements.
  _atomium_form_element_theme_alter($form, $form_state, $form_id);

  /*
   * Prevent user-facing field styling from screwing up node edit forms by
   * renaming the classes on the node edit form's field wrappers.
   *
   * Remove if #1245218 is backported to D7 core.
   */
  foreach (\array_keys($form) as $item) {
    if (0 === \strpos($item, 'field_')) {
      if (!empty($form[$item]['#attributes']['class'])) {
        foreach ($form[$item]['#attributes']['class'] as &$class) {
          // Core bug: the field-type-text-with-summary class
          // is used as a JS hook.
          if ('field-type-text-with-summary' != $class && 0 === \strpos($class,
              'field-type-') || 0 === \strpos($class, 'field-name-')) {
            // Make the class different from that used in theme_field().
            $class = 'form-' . $class;
          }
        }
      }
    }
  }
}

/**
 * Custom callback.
 *
 * This function will alter all the element in a form and update their
 * #theme key to append the $form_id at the end so we can preprocess them.
 *
 * @see form_builder()
 */
function _atomium_form_element_theme_alter(array &$form, array &$form_state, $form_id) {
  foreach (element_children($form) as $key) {
    if (isset($form[$key]['#type']) && empty($form[$key]['#defaults_loaded']) && ($info = element_info($form[$key]['#type']))) {
      if (isset($info['#theme'])) {
        $form[$key]['#theme'] = _atomium_extend_with_suggestions(
          (array) $info['#theme'],
          array('form', $form_id, $key)
        );
      }

      if (isset($info['#theme_wrappers'])) {
        $form[$key] += array('#theme_wrappers' => array());
        $form[$key]['#theme_wrappers'] = \array_merge($form[$key]['#theme_wrappers'], $info['#theme_wrappers']);

        $form[$key]['#theme_wrappers'] = _atomium_extend_with_suggestions(
          $info['#theme_wrappers'],
          array('form', $form_id, $key)
        );
      }
    }

    _atomium_form_element_theme_alter($form[$key], $form_state, $form_id);
  }
}

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
