<?php

/**
 * @file
 * Contains element file.
 *
 * This custom element is based on the html_tag element from Drupal core.
 * The origin of this element comes from a discussion on drupal.org and the use
 * of html_tag element.
 *
 * @see https://www.drupal.org/project/drupal/issues/2981726
 *
 * The differences are:
 *  - It render the children element if any,
 *  - It ensure that the '#tag' is plain text
 *  - Automatically uses a void element (hr, img, etc etc...)
 *  - Extend #theme key based on suggestions in #theme_hook_suggestions_parts
 */

/**
 * Implements hook_atomium_element_info_hook().
 */
function atomium_atomium_element_info_atomium_html_tag(array $types) {
  return array(
    'atomium_html_tag' => array(
      '#attributes' => array(),
      '#pre_render' => array(
        'drupal_pre_render_conditional_comments',
        'atomium_pre_render_extend_theme_property',
        'atomium_pre_render_atomium_html_tag',
        'atomium_pre_render_children',
      ),
      '#theme' => 'atomium_html_tag',
      '#type' => 'atomium_html_tag',
      '#tag' => NULL,
      '#theme_hook_suggestions_parts' => array(),
      '#prefix' => '',
      '#suffix' => '',
    ),
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
function atomium_pre_render_extend_theme_property(array $element) {
  $element += array('#theme_hook_suggestions_parts' => array());

  if (isset($element['#tag'])) {
    array_unshift(
      $element['#theme_hook_suggestions_parts'],
      $element['#tag']
    );
  }

  if (!empty($element['#theme_hook_suggestions_parts'])) {
    $element['#theme'] .= '__' . implode('__', $element['#theme_hook_suggestions_parts']);
  }

  return $element;
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
function atomium_pre_render_atomium_html_tag(array $element) {
  // Void elements do not contain values or closing tags.
  // @see http://www.w3.org/TR/html5/syntax.html#syntax-start-tag
  // @see http://www.w3.org/TR/html5/syntax.html#void-elements
  $void_elements = array(
    'area', 'base', 'br', 'col', 'embed', 'hr', 'img', 'input',
    'keygen', 'link', 'meta', 'param', 'source', 'track', 'wbr',
    'rect', 'circle', 'polygon', 'ellipse', 'stop', 'use', 'path',
  );

  $element['#tag'] = check_plain($element['#tag']);

  $suggestions = array(
    $element['#tag'],
  );

  if (in_array($element['#tag'], $void_elements, TRUE)) {
    $suggestions[] = 'void';
  }

  array_unshift(
    $element['#theme_hook_suggestions_parts'],
    ...array_reverse($suggestions)
  );

  $element += array(
    '#children' => '',
  );

  $value = isset($element['#value']) ? $element['#value'] : '';

  // This is to avoid issue when $value is not a string like with the date
  // type where $value is an array containing multiple values.
  if (!is_string($value)) {
    $value = '';
  }

  // We concatenate the #value key to remain completely compatible with the
  // 'html_tag' core type.
  $element['#children'] .= $value;

  return $element;
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
function atomium_pre_render_children(array $element) {
  $element += array('#children' => '');

  // Render the element children if any.
  $element['#children'] .= drupal_render_children($element);

  return $element;
}
