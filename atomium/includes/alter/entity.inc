<?php

/**
 * @file
 * entity.inc
 */

/**
 * Implements hook_entity_view_alter().
 *
 * @see https://www.drupal.org/sandbox/onkeltem/1730244
 */
function atomium_entity_view_alter(array &$build, $type) {
  if (isset($build['#' . $type])) {
    $entity = $build['#' . $type];
    $info = entity_get_info($type);

    if (!empty($entity->{$info['entity keys']['id']})) {
      $build['#contextual_links'][$type] = array($type, array($entity->{$info['entity keys']['id']}));
    }
  }

  $build['#theme'] = _atomium_extend_theme_hook($build['#theme'], array($build['#bundle'], $build['#view_mode']));
}
