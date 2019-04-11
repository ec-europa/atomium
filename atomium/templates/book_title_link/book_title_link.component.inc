<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_book_title_link(array $existing, $type, $theme, $path) {
  return array(
    'book_title_link' => array(
      'template' => 'book-title-link',
      'variables' => array(
        'link' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_book_title_link(array &$variables, $hook) {
  $link = $variables['link'];

  $link['options']['attributes']['class'] = array('book-title');

  $book_title_link = array(
    '#theme' => _atomium_extend_theme_hook(
      'link',
      array(
        $variables['theme_hook_original'],
      )
    ),
    '#text' => $link['title'],
    '#path' => $link['href'],
    '#options' => $link['options'],
  );

  $variables[$variables['base_hook']] = array(
    $variables['base_hook'] => $book_title_link,
  );
}
