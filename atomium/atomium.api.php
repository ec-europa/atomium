<?php

/**
 * @file
 * API file of Atomium theme.
 */
?>

<?
/**
 * Register one or many Atomium component implementations.
 *
 * This function is a subfunction of the Drupal's hook_theme() hook.
 * Its signature and the return values are identical.
 *
 * It must live in: [path_to_theme]/templates/[hook]/[hook].component.inc
 *
 * @see hook_theme()
 */
function hook_atomium_theme_hook(&$existing, $type, $theme, $path) {
  return array(
    'my_custom_component' => array(
      'template' => 'my-custom-component',
      'variables' => array(
        'var1' => NULL,
        'var2' => array(),
        'var3' => 'div',
      ),
    ),
  );
}
