<?php

/**
 * @file
 * Contains element file.
 */

/**
 * Implements hook_atomium_element_info_hook().
 */
function atomium_atomium_element_info_atomium_link(array $types) {
  $link = $types['link'];

  $link['#theme'] = 'link';

  foreach ($link['#pre_render'] as $key => $pre_render_callback) {
    if ($pre_render_callback === 'drupal_pre_render_link') {
      $link['#pre_render'][$key] = 'atomium_pre_render_link';
    }

    if ($pre_render_callback === 'drupal_pre_render_markup') {
      unset($link['#pre_render'][$key]);
    }
  }

  $link['#pre_render'] = array_merge(
    $link['#pre_render'],
    array(
      'atomium_pre_render_extend_theme_property',
      'atomium_pre_render_children',
      'atomium_pre_render_children_link',
      'atomium_pre_render_link_property_mapper',
    )
  );

  return array(
    'atomium_link' => $link,
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
function atomium_pre_render_link_property_mapper(array $element) {
  $element += array(
    '#text' => isset($element['#title']) ? $element['#title'] : NULL,
    '#path' => isset($element['#href']) ? $element['#href'] : NULL,
  );

  return $element;
}

/**
 * Custom pre_render callback.
 *
 * This callback will replace the original drupal_pre_render_link callback.
 * In order to make sure that we are always dealing with render arrays,
 * this pre_render will be a concatenation of drupal_pre_render_link() and the
 * l() function.
 *
 * @param array $element
 *   The element to alter.
 *
 * @return array
 *   The element altered.
 *
 * @see \drupal_pre_render_link()
 * @see \l()
 */
function atomium_pre_render_link(array $element) {
  global $language_url;

  // By default, link options to pass to l() are normally set in #options.
  $element += array('#options' => array());

  // Merge in defaults.
  $element['#options'] += array(
    'attributes' => array(),
    // See https://www.drupal.org/node/1410574
    'query' => array(),
    'html' => FALSE,
  );

  // However, within the scope of renderable elements, #attributes is a valid
  // way to specify attributes, too. Take them into account, but do not override
  // attributes from #options.
  if (isset($element['#attributes'])) {
    $element['#options']['attributes'] += $element['#attributes'];
  }

  // This #pre_render callback can be invoked from inside or outside of a Form
  // API context, and depending on that, a HTML ID may be already set in
  // different locations. #options should have precedence over Form API's #id.
  // #attributes have been taken over into #options above already.
  if (isset($element['#options']['attributes']['id'])) {
    $element['#id'] = $element['#options']['attributes']['id'];
  }
  elseif (isset($element['#id'])) {
    $element['#options']['attributes']['id'] = $element['#id'];
  }

  // Conditionally invoke ajax_pre_render_element(), if #ajax is set.
  if (isset($element['#ajax']) && !isset($element['#ajax_processed'])) {
    // If no HTML ID was found above, automatically create one.
    if (!isset($element['#id'])) {
      $element['#id'] = $element['#options']['attributes']['id'] = drupal_html_id('ajax-link');
    }
    // If #ajax['path] was not specified, use the href as Ajax request URL.
    if (!isset($element['#ajax']['path'])) {
      $element['#ajax']['path'] = $element['#href'];
      $element['#ajax']['options'] = $element['#options'];
    }
    $element = ajax_pre_render_element($element);
  }

  // The link is only active, if its path corresponds to the current path, the
  // language of the linked path is equal to the current language, and if the
  // query parameters of the link equal those of the current request, since the
  // same request with different query parameters may yield a different page
  // (e.g., pagers).
  // See https://www.drupal.org/node/1410574
  $is_active = ($element['#href'] === current_path() || ($element['#href'] === '<front>' && drupal_is_front_page()));
  $is_active = $is_active && (empty($element['#options']['language']) || $element['#options']['language']->language === $language_url->language);
  if ($is_active === TRUE) {
    // The query parameters of the current request are in $_GET, but the 'q'
    // parameter in there should be ignored, as that is the Drupal path.
    $real_query_params = $_GET;
    unset($real_query_params['q']);
    $is_active = $real_query_params === $element['#options']['query'];
  }

  // Append active class.
  if ($is_active === TRUE) {
    $element['#options']['attributes']['class'][] = 'active';
  }

  // Remove all HTML and PHP tags from a tooltip. For best performance, we act
  // only if a quick strpos() pre-check gave a suspicion (because strip_tags()
  // is expensive).
  if (isset($element['#options']['attributes']['title']) && strpos($element['#options']['attributes']['title'], '<') !== FALSE) {
    $element['#options']['attributes']['title'] = strip_tags($element['#options']['attributes']['title']);
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
function atomium_pre_render_children_link(array $element) {
  $element['#title'] .= $element['#children'];

  return $element;
}
