<?php

/**
 * @file
 * API file of Atomium theme.
 */

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

/**
 * Allows you to define a preview in the /atomium-overview page.
 *
 * It must live in: [path_to_theme]/templates/[hook]/[hook].component.inc.
 * 'disable': Set to TRUE to disable the preview.
 */
function hook_atomium_definition_hook(&$existing, $type, $theme, $path) {
  return array(
    'hook' => array(
      'name' => 'My component name',
      'description' => 'My component description',
      'disable' => FALSE,
      'preview' => array(
        'title' => 'The title variable of my component',
      ),
    ),
  );
}

/**
 * Allows you to define a preview using a form in the /atomium-overview page.
 *
 * It must live in: [path_to_theme]/templates/[hook]/[hook].component.inc.
 *
 * @return array
 *   The Drupal form.
 */
function hook_atomium_definition_form_hook($form, &$form_state) {
  $form['component'] = array(
    '#theme' => 'username',
    '#account' => user_load(1),
  );

  return $form;
}
