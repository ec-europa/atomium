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
 */
function atomium_preprocess_links(array &$variables, $hook) {
  $heading = $variables['heading'];

  $variables['atomium']['attributes']['wrapper']
    ->merge($variables['attributes']);
  $variables['atomium']['attributes']['wrapper']
    ->append('class', 'links');

  // Treat the heading first if it is present to prepend it to the
  // list of links.
  if (!empty($variables['heading'])) {
    $heading = $variables['heading'];

    if (\is_string($heading)) {
      $heading = array(
        '#type' => 'html_tag',
        '#tag' => 'h2',
        '#value' => $variables['heading'],
      );
    }

    $heading += array(
      'class' => array(),
    );

    if (isset($heading['text'], $heading['level'])) {
      $heading = array(
        '#type' => 'html_tag',
        '#tag' => $heading['level'],
        '#value' => $heading['text'],
        '#attributes' => $variables['atomium']['attributes']['heading']
          ->merge(
            array(
              'class' => $heading['class'],
            )
        )
          ->toArray(),
      );
    }
  }

  $new_links = array();

  foreach ($variables['links'] as $key => $link) {
    if (isset($link['href'])) {
      $new_links[] = array(
        'data' => array(
          'link' => array(
            '#type' => 'link',
            '#title' => $link['title'],
            '#href' => $link['href'],
            '#options' => $link,
          ),
          '#attributes' => array(
            'class' => array(
              $key,
            ),
          ),
        ),
      );
    }

    if (isset($link['title']) && !empty($link['title']) && empty($link['href'])) {
      // Some links are actually not links, but we wrap these in <span> for
      // adding title and class attributes.
      if (empty($link['html'])) {
        $new_links[] = array(
          'data' => array(
            'link' => array(
              '#type' => 'html_tag',
              '#tag' => 'span',
              '#value' => check_plain($link['title']),
            ),
          ),
        );
      }
    }
  }

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => array(
      '#theme' => _atomium_extend_theme_hook(
        'item_list',
        $variables['theme_hook_original']
      ),
      '#items' => $new_links,
      '#atomium' => array(
        'attributes' => array(
          'list' => $variables['atomium']['attributes']['wrapper'],
        ),
      ),
      '#wrapper' => FALSE,
      '#title' => $heading,
    ),
  );
}
