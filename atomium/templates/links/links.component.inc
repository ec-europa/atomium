<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_links(array $existing, $type, $theme, $path) {
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
 * Implements hook_preprocess_hook().
 *
 * @SuppressWarnings(PHPMD.CyclomaticComplexity)
 * @SuppressWarnings(PHPMD.NPathComplexity)
 */
function atomium_preprocess_links(array &$variables, $hook) {
  $language_url = $GLOBALS['language_url'];

  $count = \count($variables['links']);
  if ($count <= 0) {
    return;
  }

  $heading = $variables['heading'];

  $variables['atomium']['attributes']['wrapper']->merge($variables['attributes']);
  $variables['atomium']['attributes']['wrapper']->append('class', 'links');

  // Treat the heading first if it is present to prepend it to the
  // list of links.
  if (!empty($variables['heading'])) {
    if (\is_string($variables['heading'])) {
      // Prepare the array that will be used when the passed heading
      // is a string.
      $variables['heading'] = array(
        'text' => $variables['heading'],
        // Set the default level of the heading.
        'level' => 'h2',
      );
    }
    if (!empty($variables['heading']['class'])) {
      $variables['atomium']['attributes']['heading']->merge(array(
        'class' => $heading['class'],
      ));
    }
    $variables['heading']['text'] = check_plain($variables['heading']['text']);
  }

  $num_links = $count;
  $i = 1;
  $new_links = array();

  foreach ($variables['links'] as $key => $link) {
    $link['attributes_array'] = array('class' => array($key));
    $link['span_attributes_array'] = array();

    // Add first, last and active classes to the list of links to help out
    // themers.
    if ($i === 1) {
      $link['attributes_array']['class'][] = 'first';
    }

    if ($i === $num_links) {
      $link['attributes_array']['class'][] = 'last';
    }

    if (
      isset($link['href']) &&
      (empty($link['language']) || $link['language']->language === $language_url->language) &&
      ($link['href'] === $_GET['q'] || ($link['href'] === '<front>' && drupal_is_front_page()))) {
      $link['attributes_array']['class'][] = 'active';
    }

    $newlink = '';
    if (isset($link['href'])) {
      // Pass in $link as $options, they share the same keys.
      $newlink = array(
        'link' => array(
          '#theme' => _atomium_extend_theme_hook(
            'link',
            $variables['theme_hook_original']
          ),
          '#text' => $link['title'],
          '#path' => $link['href'],
          '#options' => $link,
        ),
        '#theme_wrappers' => _atomium_extend_theme_hook(
          'html_tag',
          $variables['theme_hook_original']
        ),
        '#tag' => 'li',
        '#attributes' => $link['attributes_array'],
      );
    }

    if (isset($link['title']) && !empty($link['title']) && empty($link['href'])) {
      $link['span_attributes_array'] = array();
      if (isset($link['attributes_array'])) {
        $link['span_attributes_array'] = $link['attributes_array'];
      }

      // Some links are actually not links, but we wrap these in <span> for
      // adding title and class attributes.
      if (empty($link['html'])) {
        $newlink = array(
          'link' => array(
            '#markup' => check_plain($link['title']),
            '#theme_wrappers' => _atomium_extend_theme_hook(
              'html_tag',
              $variables['theme_hook_original']
            ),
            '#tag' => 'span',
            '#attributes' => $link['span_attributes_array'],
          ),
          '#theme_wrappers' => _atomium_extend_theme_hook(
            'html_tag',
            $variables['theme_hook_original']
          ),
          '#tag' => 'li',
          '#attributes' => $link['attributes_array'],
        );
      }
    }

    $i++;
    $new_links[] = $newlink;
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        $variables['theme_hook_original']
      ),
      '#items' => \array_filter($new_links),
      '#type' => 'ul',
      '#atomium' => array(
        'attributes' => array(
          'list' => $variables['atomium']['attributes']['wrapper'],
        ),
      ),
    ),
  );
}
