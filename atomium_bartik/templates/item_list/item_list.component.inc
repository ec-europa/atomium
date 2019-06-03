<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_preprocess_hook().
 */
function atomium_bartik_preprocess_item_list__links__system_secondary_menu(array &$variables, $hook) {
  $variables['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#attributes' => array(
      'class' => array(
        'element-invisible',
      ),
    ),
    '#value' => t('Secondary menu'),
  );
}
