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
function atomium_preprocess_block(&$variables, $hook) {
  // Add BEM style classes to the block.
  $variables['atomium']['attributes']['wrapper']->append('class', 'hook__block__' . $variables['block']->module . '__' . $variables['block']->delta);

  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('block')));
  $variables['classes_array'] = preg_grep('/^block-/', $variables['classes_array'], PREG_GREP_INVERT);
  $variables['classes_array'][] = $variables['block_html_id'];
  $variables['classes_array'][] = $variables['block_zebra'];

  if (isset($variables['block']->order) && !empty($variables['block']->order)) {
    $variables['classes_array'][] = 'order-' . $variables['block']->order;
  }
  if (isset($variables['block']->classes) && is_array($variables['block']->classes)) {
    $variables['classes_array'] = array_merge($variables['classes_array'], (array) $variables['block']->classes);
  }

  if (
    ($variables['elements']['#block']->module == "system" and $variables['elements']['#block']->delta == "navigation") or
    ($variables['elements']['#block']->module == "system" and $variables['elements']['#block']->delta == "main-menu") or
    ($variables['elements']['#block']->module == "system" and $variables['elements']['#block']->delta == "user-menu") or
    ($variables['elements']['#block']->module == "admin" and $variables['elements']['#block']->delta == "menu") or
    $variables['elements']['#block']->module == "menu_block"
  ) {
    $variables['theme_hook_suggestions'][] = 'block__menu';
  }

  $variables['atomium']['attributes']['wrapper']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['wrapper']->append('id', $variables['block_html_id']);

  // Add Aria Roles via attributes.
  switch ($variables['block']->module) {
    case 'system':
      switch ($variables['block']->delta) {
        case 'main':
          // Note: the "main" role goes in the page.tpl, not here.
          break;

        case 'help':
        case 'powered-by':
          $variables['atomium']['attributes']['wrapper']->append('role', 'complementary');
          break;

        default:
          // Any other "system" block is a menu block.
          $variables['atomium']['attributes']['wrapper']->append('role', 'navigation');
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
      $variables['atomium']['attributes']['wrapper']->append('role', 'navigation');
      break;

    case 'search':
      $variables['atomium']['attributes']['wrapper']->append('role', 'search');
      break;

    case 'help':
    case 'aggregator':
    case 'locale':
    case 'poll':
    case 'profile':
      $variables['atomium']['attributes']['wrapper']->append('role', 'complementary');
      break;

    case 'node':
      switch ($variables['block']->delta) {
        case 'syndicate':
          $variables['atomium']['attributes']['wrapper']->append('role', 'complementary');
          break;

        case 'recent':
          $variables['atomium']['attributes']['wrapper']->append('role', 'navigation');
          break;
      }
      break;

    case 'user':
      switch ($variables['block']->delta) {
        case 'login':
          $variables['atomium']['attributes']['wrapper']->append('role', 'form');
          break;

        case 'new':
        case 'online':
          $variables['atomium']['attributes']['wrapper']->append('role', 'complementary');
          break;
      }
      break;
  }

  $variables['atomium']['attributes']['wrapper']->append('class', drupal_html_class('block-' . $variables['block']->module));

  $variables['title']['#markup'] = '';
  if ($variables['block']->subject) {
    $variables['title'] = array(
      '#markup' => $variables['block']->subject,
      '#theme_wrappers' => array('html_tag__' . $variables['theme_hook_original'] . '__h2'),
      '#tag' => 'h2',
      '#attributes' => $variables['title_attributes_array'],
    );
  }
}
