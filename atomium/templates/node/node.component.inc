<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_preprocess_node(array &$variables, $hook) {
  // One unified node teaser template.
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];

  if ($variables['promote']) {
    $variables['classes_array'][] = 'node__promote';
    $variables['theme_hook_suggestions'][] = 'node__promote';
  }

  if ($variables['sticky']) {
    $variables['classes_array'][] = 'node__sticky';
    $variables['theme_hook_suggestions'][] = 'node__sticky';
  }

  if ($variables['is_front']) {
    $variables['classes_array'][] = 'node__front';
    $variables['theme_hook_suggestions'][] = 'node__front';
  }

  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;
  if ('0' == $variables['status']) {
    $variables['classes_array'][] = 'node__unpublished';
    $variables['theme_hook_suggestions'][] = 'node__unpublished';
  }

  $variables['preview'] = isset($variables['preview']) ? $variables['preview'] : FALSE;
  if (isset($variables['preview'])) {
    $variables['classes_array'][] = 'node__preview';
    $variables['theme_hook_suggestions'][] = 'node__preview';
  }

  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  // Add a noderef to the list.
  if (isset($variables['referencing_field'])) {
    $variables['theme_hook_suggestions'][] = 'node__noderef';
    $variables['theme_hook_suggestions'][] = 'node__noderef__' . $variables['type'];
    $variables['theme_hook_suggestions'][] = 'node__noderef__' . $variables['type'] . '__' . $variables['view_mode'];
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

  $variables['atomium']['attributes']['wrapper']->append('class', $variables['classes_array']);
  $variables['atomium']['attributes']['wrapper']->remove('class', atomium_get_settings('preprocess.node.classes_to_remove', TRUE));
  $variables['atomium']['attributes']['wrapper']->append('role', 'article');
  $variables['atomium']['attributes']['wrapper']->append('id', 'node-' . $variables['nid']);
}
