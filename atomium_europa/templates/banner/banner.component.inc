<?php

/**
 * @file
 * Contains component file.
 */

/**
 * Implements hook_atomium_theme_HOOK().
 */
function atomium_europa_atomium_theme_banner() {
  return array(
    'banner' => array(
      'variables' => array(
        'quote' => NULL,
        'author' => NULL,
      ),
      'template' => 'banner',
    ),
  );
}

/**
 * Implements hook_atomium_definition_HOOK().
 */
function atomium_europa_atomium_definition_banner() {
  return array(
    'label' => 'Banner',
    'description' => 'Banner.',
    'preview' => array(
      'quote' => 'Nullam eget gravida sapien. Curabitur nec ligula varius tellus blandit auctor in non felis. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Pellentesque in volutpat eros, ut fringilla tortor.',
      'author' => 'President Juncker',
    ),
  );
}
