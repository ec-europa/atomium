<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_block() {
  return array(
    'block' => array(
      'render element' => 'elements',
      'template' => 'block',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_block(&$variables) {
  // Add BEM style classes to the block.
  $variables['attributes_array']['class'][] = 'hook__block__' . $variables['block']->module . '__' . $variables['block']->delta;

  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('block')));
  $variables['classes_array'] = preg_grep('/^block-/', $variables['classes_array'], PREG_GREP_INVERT);
  $variables['id_block'] = ' id="' . $variables['block_html_id'] . '"';
  $variables['classes_array'][] = $variables['block_html_id'];
  $variables['classes_array'][] = $variables['block_zebra'];

  if (isset($variables['block']->order) && !empty($variables['block']->order)) {
    $variables['classes_array'][] = 'order-' . $variables['block']->order;
  }
  if (isset($variables['block']->classes) && is_array($variables['block']->classes)) {
    $variables['classes_array'] = array_merge($variables['classes_array'], (array) $variables['block']->classes);
  }

  $variables['title_attributes_array']['class'][] = 'title';
  $variables['content_attributes_array']['class'][] = 'block-content';

  if (
    ($variables['elements']['#block']->module == "system" and $variables['elements']['#block']->delta == "navigation") or
    ($variables['elements']['#block']->module == "system" and $variables['elements']['#block']->delta == "main-menu") or
    ($variables['elements']['#block']->module == "system" and $variables['elements']['#block']->delta == "user-menu") or
    ($variables['elements']['#block']->module == "admin" and $variables['elements']['#block']->delta == "menu") or
    $variables['elements']['#block']->module == "menu_block"
  ) {
    $variables['theme_hook_suggestions'][] = 'block__menu';
  }

  $variables['attributes_array']['class'] = array_merge($variables['attributes_array']['class'], $variables['classes_array']);
  $variables['attributes_array']['id'] = $variables['block_html_id'];

  // Add Aria Roles via attributes.
  switch ($variables['block']->module) {
    case 'system':
      switch ($variables['block']->delta) {
        case 'main':
          // Note: the "main" role goes in the page.tpl, not here.
          break;

        case 'help':
        case 'powered-by':
          $variables['attributes_array']['role'] = 'complementary';
          break;

        default:
          // Any other "system" block is a menu block.
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;

    case 'menu':
    case 'menu_block':
    case 'blog':
    case 'book':
    case 'comment':
    case 'forum':
    case 'shortcut':
    case 'statistics':
      $variables['attributes_array']['role'] = 'navigation';
      break;

    case 'search':
      $variables['attributes_array']['role'] = 'search';
      break;

    case 'help':
    case 'aggregator':
    case 'locale':
    case 'poll':
    case 'profile':
      $variables['attributes_array']['role'] = 'complementary';
      break;

    case 'node':
      switch ($variables['block']->delta) {
        case 'syndicate':
          $variables['attributes_array']['role'] = 'complementary';
          break;

        case 'recent':
          $variables['attributes_array']['role'] = 'navigation';
          break;
      }
      break;

    case 'user':
      switch ($variables['block']->delta) {
        case 'login':
          $variables['attributes_array']['role'] = 'form';
          break;

        case 'new':
        case 'online':
          $variables['attributes_array']['role'] = 'complementary';
          break;
      }
      break;
  }

  $variables['classes_array'][] = drupal_html_class('block-' . $variables['block']->module);

  // Create a valid HTML ID and make sure it is unique.
  $variables['block_html_id'] = drupal_html_id('block-' . $variables['block']->module . '-' . $variables['block']->delta);

  $variables['title']['#markup'] = '';
  if ($variables['block']->subject) {
    $variables['title'] = array(
      '#markup' => $variables['block']->subject,
      '#theme_wrappers' => array('html_tag'),
      '#tag' => 'h2',
      '#attributes' => $variables['title_attributes_array'],
    );
  }

  if ($variables['content']) {
    $variables['content'] = array(
      '#markup' => $variables['content'],
      '#theme_wrappers' => array('container'),
      '#attributes' => $variables['content_attributes_array'],
    );
  }
  else {
    $variables['content'] = '';
  }
}
