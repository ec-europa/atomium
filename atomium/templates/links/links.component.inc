<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_atomium_theme_links() {
  return array(
    'links' => array(
      'template' => 'links',
      'variables' => array(
        'links' => NULL,
        'attributes' => array(
          'class' => array(
            'links',
          ),
        ),
        'heading' => array(),
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_HOOK().
 */
function atomium_preprocess_links(&$variables, $hook) {
  global $language_url;

  $links = &$variables['links'];
  $heading = $variables['heading'];

  $variables['attributes_array'] = drupal_array_merge_deep(
    $variables['attributes_array'],
    $variables['attributes']
  );
  $variables['attributes_array']['class'][] = 'links';

  if (count($links) > 0) {
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($variables['heading'])) {
      if (is_string($variables['heading'])) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $variables['heading'] = array(
          'text' => $variables['heading'],
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      if (!empty($variables['heading']['class'])) {
        $variables['heading_attributes_array'] = array(
          'class' => $heading['class'],
        );
      }
      $variables['heading']['text'] = check_plain($variables['heading']['text']);
    }

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => &$link) {
      $link['attributes_array'] = array('class' => array($key));
      $link['span_attributes_array'] = array();

      // Add first, last and active classes to the list of links to help out
      // themers.
      if ($i == 1) {
        $link['attributes_array']['class'][] = 'first';
      }
      if ($i == $num_links) {
        $link['attributes_array']['class'][] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
        && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $link['attributes_array']['class'][] = 'active';
      }

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $link['text'] = array(
          '#theme' => 'link',
          '#text' => $link['title'],
          '#path' => $link['href'],
          '#options' => $link,
        );
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for
        // adding title and class attributes.
        if (empty($link['html'])) {
          $link['text'] = check_plain($link['title']);
        }

        $link['span_attributes_array'] = array();
        if (isset($link['attributes_array'])) {
          $link['span_attributes_array'] = $link['attributes_array'];
        }
      }

      $i++;
      $link['attributes'] = atomium_drupal_attributes($link['attributes_array']);
      $link['span_attributes'] = atomium_drupal_attributes($link['span_attributes_array']);
    }
  }
}
