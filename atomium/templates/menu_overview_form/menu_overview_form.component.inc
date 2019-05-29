<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_hook().
 */
function atomium_atomium_theme_menu_overview_form(array $existing, $type, $theme, $path) {
  return array(
    'menu_overview_form' => array(
      'template' => 'menu-overview-form',
      'render element' => 'form',
    ),
  );
}

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_menu_overview_form(array &$variables, $hook) {
  $form = $variables['form'];

  drupal_add_tabledrag(
    'menu-overview',
    'match',
    'parent',
    'menu-plid',
    'menu-plid',
    'menu-mlid',
    TRUE,
    MENU_MAX_DEPTH - 1
  );
  drupal_add_tabledrag(
    'menu-overview',
    'order',
    'sibling',
    'menu-weight'
  );

  $header = array(
    t('Menu link'),
    array('data' => t('Enabled'), 'class' => array('checkbox')),
    t('Weight'),
    array('data' => t('Operations'), 'colspan' => '3'),
  );

  $rows = array();
  foreach (element_children($form) as $mlid) {
    if (!isset($form[$mlid]['hidden'])) {
      continue;
    }

    $element = &$form[$mlid];

    // Add special classes to be used for tabledrag.js.
    $element['plid']['#attributes']['class'] = array('menu-plid');
    $element['mlid']['#attributes']['class'] = array('menu-mlid');
    $element['weight']['#attributes']['class'] = array('menu-weight');

    // Change the parent field to a hidden.
    // This allows any value but hides the field.
    $element['plid']['#type'] = 'hidden';

    $row = array();
    $row[] = array(
      'data' => array(
        'indentation' => array(
          '#theme' => 'indentation',
          '#size' => $element['#item']['depth'] - 1,
          '#weight' => -10,
        ),
        'title' => $element['title'],
      ),
    );
    $row[] = array(
      'data' => $element['hidden'],
      'class' => array('checkbox', 'menu-enabled'),
    );
    $row[] = array(
      'data' => array(
        'weight' => $element['weight'],
        'plid' => $element['plid'],
        'mlid' => $element['mlid'],
      ),
    );

    // Build a list of operations.
    foreach (element_children($element['operations']) as $op) {
      $row[$op] = array(
        'data' => $element['operations'][$op],
        'class' => array('menu-operations'),
      );
    }

    if (!isset($row['reset'])) {
      $row['reset'] = array();
    }

    $row = \array_merge(
      array('data' => $row),
      $element['#attributes']
    );
    $row['class'][] = 'draggable';
    $rows[] = $row;
    unset($variables['form'][$mlid]);
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => $form['#empty_text'], 'colspan' => '7'));
  }

  $variables['form']['table'] = array(
    '#theme' => _atomium_extend_with_suggestions(
      array('table'),
      array(
        $variables['theme_hook_original'],
        $variables['form']['#menu']['menu_name'],
      )
    ),
    '#header' => $header,
    '#rows' => $rows,
    '#atomium' => array(
      'attributes' => array(
        'wrapper' => array(
          'id' => 'menu-overview',
        ),
      ),
    ),
  );
}
