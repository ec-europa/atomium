<?php

/**
 * @file
 * node.preprocess.inc
 */

/**
 * Implements hook_preprocess_node().
 */
function atomium_preprocess_node(&$variables) {
  // One unified node teaser template.
  if ($variables['view_mode'] == "teaser") {
    $variables['theme_hook_suggestions'][] = 'node__nodeteaser';
  }

  if ($variables['view_mode'] == "teaser" and $variables['promote']) {
    $variables['theme_hook_suggestions'][] = 'node__nodeteaser__promote';
  }

  if ($variables['view_mode'] == "teaser" and $variables['sticky']) {
    $variables['theme_hook_suggestions'][] = 'node__nodeteaser__sticky';
  }

  if ($variables['view_mode'] == "teaser" and $variables['is_front']) {
    $variables['theme_hook_suggestions'][] = 'node__nodeteaser__front';
  }

  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  // Add a noderef to the list.
  if (isset($variables['referencing_field'])) {
    $variables['theme_hook_suggestions'][] = 'node__noderef';
    $variables['theme_hook_suggestions'][] = 'node__noderef__' . $variables['type'];
    $variables['theme_hook_suggestions'][] = 'node__noderef__' . $variables['type'] . '__' . $variables['view_mode'];
  }

  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('node')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('node-sticky')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('node-unpublished')));
  $variables['classes_array'] = array_values(array_diff($variables['classes_array'], array('node-promoted')));

  // Change node-xxx to a more generalised name so we can use the same class
  // other places in the comments.
  $variables['classes_array'] = array_values(
    array_diff(
      $variables['classes_array'],
      array('node-sticky', 'node-unpublished', 'node-promoted')
    )
  );

  if ($variables['promote']) {
    $variables['classes_array'][] = 'promote';
  }
  if ($variables['sticky']) {
    $variables['classes_array'][] = 'sticky';
  }
  if ('0' == $variables['status']) {
    $variables['classes_array'][] = 'unpublished';
  }

  if (isset($variables['preview'])) {
    $variables['classes_array'][] = 'node-preview';
  }

  $variables['id_node'] = 'node-' . $variables['nid'];

  // Remove class from the ul that holds the links <ul class="inline links">.
  // This is generated in the node_build_content() function in the node.module.
  $variables['content']['links']['#attributes']['class'] = array_values(array_diff($variables['content']['links']['#attributes']['class'], array('inline')));
  $variables['content']['links']['#attributes']['class'] = array_values(array_diff($variables['content']['links']['#attributes']['class'], array('links')));

  // Remove the class attribute it its empty.
  if (isset($variables['content']['links']['#attributes']['class']) && empty($variables['content']['links']['#attributes']['class'])) {
    unset($variables['content']['links']['#attributes']['class']);
  }

  // Add $unpublished variable.
  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;

  // Set preview variable to FALSE if it doesn't exist.
  $variables['preview'] = isset($variables['preview']) ? $variables['preview'] : FALSE;

  // Add pubdate to submitted variable.
  $variables['pubdate'] = '<time pubdate datetime="' . format_date($variables['node']->created, 'custom', 'c') . '">' . $variables['date'] . '</time>';
  if ($variables['display_submitted']) {
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['name'], '!datetime' => $variables['pubdate']));
  }

  // Add a class for the view mode.
  $variables['classes_array'][] = 'view-mode-' . $variables['view_mode'];

  // Add a class to show node is authored by current user.
  if ($variables['uid'] && $variables['uid'] == $GLOBALS['user']->uid) {
    $variables['classes_array'][] = 'node-by-viewer';
  }

  $variables['classes_array'][] = 'node-' . $variables['nid'];
  $variables['attributes_array']['class'] = array_merge($variables['classes_array'], $variables['attributes_array']['class']);
  $variables['attributes_array']['role'] = 'article';
  $variables['attributes_array']['id'] = 'node-' . $variables['nid'];
}
